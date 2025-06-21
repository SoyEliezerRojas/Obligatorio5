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

void ManejadorPelicula::agregarPuntaje(Puntaje* puntaje) {
    puntajes.push_back(puntaje);
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

bool ManejadorPelicula::eliminarPelicula(string titulo) {
    for (auto it = peliculas.begin(); it != peliculas.end(); ++it) {
        if ((*it)->getTitulo() == titulo) {
            delete *it;
            peliculas.erase(it);
            return true;
        }
    }
    return false;
}

ManejadorPelicula::~ManejadorPelicula() {
    for (Pelicula* pelicula : peliculas) {
        delete pelicula;
    }
    peliculas.clear();
}
