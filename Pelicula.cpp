#include "Pelicula.h"
#include <string>
#include <stdexcept>
using namespace std;

Pelicula::Pelicula() {
    this->puntajeProm = 0;
}

Pelicula::Pelicula(string titulo, string sinopsis, float puntajeProm, string poster) {
    this->titulo = titulo;
    this->sinopsis = sinopsis;
    this->puntajeProm = puntajeProm;
    this->poster = poster;
}

string Pelicula::getTitulo() {
    return this->titulo;
}

void Pelicula::setTitulo(string titulo) {
    this->titulo = titulo;
}

string Pelicula::getSinopsis() {
    return this->sinopsis;
}

void Pelicula::setSinopsis(string sinopsis) {
    this->sinopsis = sinopsis;
}

float Pelicula::getPuntajeProm() {
    return this->puntajeProm;
}

void Pelicula::setPuntajeProm(float puntajeProm) {
    this->puntajeProm = puntajeProm;
}

string Pelicula::getPoster() {
    return this->poster;
}

void Pelicula::setPoster(string poster) {
    this->poster = poster;
}

void Pelicula::agregarCine(Cine* cine) {
    if (cine != NULL) {
        this->cines.push_back(cine);
    }
}

list<Cine*> Pelicula::getCines() {
    return this->cines;
}

DtPelicula Pelicula::getDtPelicula() {
    return DtPelicula(this->titulo, this->sinopsis, this->poster, this->puntajeProm);
}

list<DtReserva> Pelicula::listarReservas() {
    list<DtReserva> reservas;
    for (list<Cine*>::iterator it = cines.begin(); it != cines.end(); ++it) {
        list<DtReserva> reservasCine = (*it)->listarReservasDePelicula(this->titulo);
        reservas.insert(reservas.end(), reservasCine.begin(), reservasCine.end());
    }
    return reservas;
}

Pelicula::~Pelicula() {}