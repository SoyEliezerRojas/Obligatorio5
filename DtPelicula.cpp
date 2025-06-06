#include "DtPelicula.h"

DtPelicula::DtPelicula(){}

DtPelicula::DtPelicula(string titulo, string sinopsis, string poster, float puntajePromedio){
	this->titulo = titulo;
	this->sinopsis = sinopsis;
	this->poster = poster;
	this->puntajePromedio = puntajePromedio;
}

string DtPelicula::getTitulo() {
	return this->titulo;
}

string DtPelicula::getSinopsis() {
	return this->sinopsis;
}

string DtPelicula::getPoster() {
	return this->poster;
}

float DtPelicula::getPuntajePromedio() {
	return this->puntajePromedio;
}

DtPelicula::~DtPelicula(){}

ostream& operator << (ostream& salida, const DtPelicula& dtPelicula){
	cout << "Título: " << dtPelicula.titulo << endl;
	cout << "Sinopsis: " << dtPelicula.sinopsis << endl;
	cout << "Poster: " << dtPelicula.poster << endl;
	cout << "Puntaje promedio: " << dtPelicula.puntajePromedio << endl;
	return salida;
}
