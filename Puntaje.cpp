#include "Puntaje.h"
#include "Pelicula.h"

Puntaje::Puntaje() {
    this->puntaje = 0;
    this->pelicula = nullptr;
    this->usuario = nullptr;
}

Puntaje::Puntaje(float puntaje, Pelicula* pelicula, Usuario* usuario) {
    this->puntaje = puntaje;
    this->pelicula = pelicula;
    this->usuario = usuario;
}

float Puntaje::getPuntaje() {
    return this->puntaje;
}

Pelicula* Puntaje::getPelicula() {
    return this->pelicula;
}

Usuario* Puntaje::getUsuario() {
    return this->usuario;
}

DtPuntaje* Puntaje::getDtPuntaje() {
    return new DtPuntaje(this->puntaje, 
                        this->usuario->getNickName(), 
                        this->pelicula->getTitulo());
}

Puntaje::~Puntaje() {
    // No hay punteros que liberar
}