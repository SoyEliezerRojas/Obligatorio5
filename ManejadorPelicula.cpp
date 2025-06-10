#include "ManejadorPelicula.h"

ManejadorPelicula* ManejadorPelicula::instancia = NULL;

ManejadorPelicula* ManejadorPelicula::getInstancia() {
    if (instancia == NULL)
        instancia = new ManejadorPelicula();
    return instancia;
}

void ManejadorPelicula::agregarPelicula(Pelicula* pelicula) {
    peliculas.push_back(pelicula);
}

Pelicula* ManejadorPelicula::buscarPelicula(string titulo) {
    for (Pelicula* pelicula : peliculas) {
        if (pelicula->getTitulo() == titulo) {
            return pelicula;
        }
    }
    return nullptr;
}

list<DtPelicula> ManejadorPelicula::listarPeliculas() {
    list<DtPelicula> dtPeliculas;
    for (Pelicula* pelicula : peliculas) {
        dtPeliculas.push_back(DtPelicula(pelicula->getTitulo(), pelicula->getSinopsis(), pelicula->getPoster(), pelicula->getPuntajeProm()));
    }
    return dtPeliculas;
}

Pelicula* ManejadorPelicula::obtenerPelicula(string titulo) {
    return buscarPelicula(titulo);
}

ManejadorPelicula::~ManejadorPelicula() {
    for (Pelicula* pelicula : peliculas) {
        delete pelicula;
    }
    peliculas.clear();
}
