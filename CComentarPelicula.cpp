#include "CComentarPelicula.h"
#include "Sesion.h"
#include <stdexcept>
#include <iostream>

using namespace std;

CComentarPelicula::CComentarPelicula() {
    this->manejadorPelicula = ManejadorPelicula::getInstancia();
    this->manejadorUsuario = ManejadorUsuario::getInstancia();
    this->peliculaSeleccionada = nullptr;
    this->nextCommentId = 1;
}

bool CComentarPelicula::hayUsuarioLogueado() {
    return Sesion::getInstancia()->getUsuario() != nullptr;
}

void CComentarPelicula::listarPeliculas() {
    list<DtPelicula> peliculas = this->manejadorPelicula->listarPeliculas();
    for (list<DtPelicula>::iterator it = peliculas.begin(); it != peliculas.end(); ++it) {
        cout << "- " << it->getTitulo() << endl;
    }
}

void CComentarPelicula::selectPeli(string titulo) {
    this->peliculaSeleccionada = this->manejadorPelicula->obtenerPelicula(titulo);
    if (this->peliculaSeleccionada == nullptr) {
        throw invalid_argument("No existe una película con ese título");
    }
}

void CComentarPelicula::comentar(string texto) {
    if (!this->hayUsuarioLogueado()) {
        throw invalid_argument("No hay usuario logueado");
    }
    
    if (this->peliculaSeleccionada == nullptr) {
        throw invalid_argument("No hay película seleccionada");
    }

    Usuario* usuarioActual = Sesion::getInstancia()->getUsuario();
    Comentario* nuevoComentario = new Comentario(texto, usuarioActual, this->peliculaSeleccionada);
    nuevoComentario->setId(this->nextCommentId);
    this->comentarios[this->nextCommentId] = nuevoComentario;
    this->nextCommentId++;
}

Comentario* CComentarPelicula::obtenerComentario(int id) {
    if (this->comentarios.count(id) > 0) {
        return this->comentarios[id];
    }
    return nullptr;
}

void CComentarPelicula::responder(int id, string texto) {
    if (!this->hayUsuarioLogueado()) {
        throw invalid_argument("No hay usuario logueado");
    }
    
    if (this->peliculaSeleccionada == nullptr) {
        throw invalid_argument("No hay película seleccionada");
    }

    Usuario* usuarioActual = Sesion::getInstancia()->getUsuario();
    Comentario* comentarioOriginal = this->obtenerComentario(id);
    if (comentarioOriginal == nullptr) {
        throw invalid_argument("No existe un comentario con ese ID");
    }

    Comentario* respuesta = new Comentario(texto, usuarioActual, this->peliculaSeleccionada);
    respuesta->setId(this->nextCommentId);
    this->comentarios[this->nextCommentId] = respuesta;
    this->nextCommentId++;
    comentarioOriginal->agregarRespuesta(respuesta);
}

CComentarPelicula::~CComentarPelicula() {
    // Solo liberamos los comentarios raíz (los que no son respuestas)
    // Las respuestas serán liberadas por el destructor de sus comentarios padre
    for (map<int, Comentario*>::iterator it = comentarios.begin(); it != comentarios.end(); ++it) {
        if (it->second->getPelicula() == this->peliculaSeleccionada) {
            delete it->second;
        }
    }
    comentarios.clear();
}