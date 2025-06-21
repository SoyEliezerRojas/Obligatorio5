#include "CComentarPelicula.h"
#include "Sesion.h"
#include <stdexcept>

using namespace std;

CComentarPelicula* CComentarPelicula::instancia = nullptr;

CComentarPelicula* CComentarPelicula::getInstancia() {
    if (instancia == nullptr) {
        instancia = new CComentarPelicula();
    }
    return instancia;
}

CComentarPelicula::CComentarPelicula() {
    this->manejadorPelicula = ManejadorPelicula::getInstancia();
    this->manejadorUsuario = ManejadorUsuario::getInstancia();
    this->peliculaSeleccionada = nullptr;
    this->nextCommentId = 1;
}

map<int, Comentario*>& CComentarPelicula::getComentarios() {
    return this->comentarios;
}

bool CComentarPelicula::hayUsuarioLogueado() {
    return Sesion::getInstancia()->getUsuario() != nullptr;
}

list<DtPelicula> CComentarPelicula::listarPeliculas() {
    return this->manejadorPelicula->listarPeliculas();
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

list<DtComentario*> CComentarPelicula::obtenerComentariosPeliculaSeleccionada() {
    list<DtComentario*> comentariosPelicula;
    
    if (this->peliculaSeleccionada == nullptr) {
        return comentariosPelicula; // Lista vacía
    }
    
    // Recorrer todos los comentarios y filtrar los de la película seleccionada que no tengan padre
    for (map<int, Comentario*>::iterator it = comentarios.begin(); it != comentarios.end(); ++it) {
        if (it->second->getPelicula()->getTitulo() == this->peliculaSeleccionada->getTitulo() && 
            it->second->getComentarioPadre() == nullptr) {
            // Convertir a DtComentario con sus respuestas
            DtComentario* dtComentario = convertirComentarioADt(it->second);
            comentariosPelicula.push_back(dtComentario);
        }
    }
    
    return comentariosPelicula;
}

// Función auxiliar para convertir Comentario a DtComentario con respuestas
DtComentario* CComentarPelicula::convertirComentarioADt(Comentario* comentario) {
    if (comentario == nullptr) return nullptr;
    
    DtComentario* dtComentario = new DtComentario(comentario->getAutor()->getNickName(), comentario->getTexto());
    
    list<Comentario*> respuestas = comentario->getRespuestas();
    for (list<Comentario*>::iterator it = respuestas.begin(); it != respuestas.end(); ++it) {
        dtComentario->agregarRespuesta(convertirComentarioADt(*it));
    }
    
    return dtComentario;
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