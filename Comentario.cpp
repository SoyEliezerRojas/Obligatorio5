#include "Comentario.h"
#include "Pelicula.h"
#include <string>
using namespace std;

Comentario::Comentario() {
    this->id = 0;
    this->texto = "";
    this->usuario = nullptr;
    this->pelicula = nullptr;
}

Comentario::Comentario(string texto, Usuario* usuario, Pelicula* pelicula) {
    this->texto = texto;
    this->usuario = usuario;
    this->pelicula = pelicula;
    // El ID debería ser asignado por el sistema
}

int Comentario::getId() {
    return this->id;
}

string Comentario::getTexto() {
    return this->texto;
}

Usuario* Comentario::getUsuario() {
    return this->usuario;
}

Pelicula* Comentario::getPelicula() {
    return this->pelicula;
}

list<Comentario*> Comentario::getRespuestas() {
    return this->respuestas;
}

void Comentario::setId(int id) {
    this->id = id;
}

void Comentario::setTexto(string texto) {
    this->texto = texto;
}

void Comentario::agregarRespuesta(Comentario* respuesta) {
    this->respuestas.push_back(respuesta);
}

Comentario::~Comentario() {
    // No liberamos usuario ni pelicula ya que no somos dueños de esos objetos
    // Pero sí liberamos las respuestas
    for (list<Comentario*>::iterator it = respuestas.begin(); it != respuestas.end(); ++it) {
        delete *it;
    }
    respuestas.clear();
}