#include "Pelicula.h"
#include "Cine.h"
#include <string>
using namespace std;

Pelicula::Pelicula() {}

Pelicula::Pelicula(string tit, string sinopsis, float puntProm, string poster){
    this->titulo = tit;
    this->sinopsis = sinopsis;
    this->puntajeProm = puntProm;
    this->poster = poster;
}

string Pelicula::getTitulo(){
    return this->titulo;
}

void Pelicula::setTit(string tit){
    this->titulo = tit;
}

string Pelicula::getSinopsis(){
    return this->sinopsis;
}

void Pelicula::setSinopsis(string sinopsis){
    this->sinopsis = sinopsis;
}

float Pelicula::getPuntajeProm(){
    return this->puntajeProm;
}

void Pelicula::setPuntajeProm(float puntProm){
    this->puntajeProm = puntProm;
}

string Pelicula::getPoster(){
    return this->poster;
}

void Pelicula::setPoster(string poster){
    this->poster = poster;
}

DtPelicula Pelicula::getDtPelicula() {
    return DtPelicula(this->titulo, this->sinopsis, this->poster, this->puntajeProm);
}

Pelicula::~Pelicula() {}