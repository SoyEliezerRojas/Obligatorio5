#include "Comentario.h"
#include <string>
using namespace std;


Comentario::Comentario() {
    this->id = 0;
    this->texto = "";
    this->autor = nullptr;
    this->pelicula = nullptr;
    this->comentarioPadre = nullptr;
}

Comentario::Comentario(string texto, Usuario* autor, Pelicula* pelicula) {
    this->texto = texto;
    this->autor = autor;
    this->pelicula = pelicula;
    this->comentarioPadre = nullptr;
}

int Comentario::getId() {
    return this->id;
}

void Comentario::setId(int id) {
    this->id = id;
}

string Comentario::getTexto() {
    return this->texto;
}

void Comentario::setTexto(string texto) {
    this->texto = texto;
}

Usuario* Comentario::getAutor() {
    return this->autor;
}

void Comentario::setAutor(Usuario* autor) {
    this->autor = autor;
}

Pelicula* Comentario::getPelicula() {
    return this->pelicula;
}

void Comentario::setPelicula(Pelicula* pelicula) {
    this->pelicula = pelicula;
}

list<Comentario*> Comentario::getRespuestas() {
    return this->respuestas;
}

void Comentario::agregarRespuesta(Comentario* respuesta) {
    respuesta->setComentarioPadre(this);
    this->respuestas.push_back(respuesta);
}

Comentario* Comentario::getComentarioPadre() {
    return this->comentarioPadre;
}

void Comentario::setComentarioPadre(Comentario* padre) {
    this->comentarioPadre = padre;
}

Comentario::~Comentario() {
    for (Comentario* respuesta : this->respuestas) {
        delete respuesta;
    }
}