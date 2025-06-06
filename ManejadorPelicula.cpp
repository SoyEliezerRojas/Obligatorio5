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
    for (Pelicula* p : peliculas) {
        if (p->getTitulo() == titulo)
            return p;
    }
    return NULL;
}

ManejadorPelicula::~ManejadorPelicula() {
    for (Pelicula* p : peliculas) {
        delete p;
    }
    peliculas.clear();
}
