#include "CAltaPelicula.h"
#include "ManejadorPelicula.h"
#include "Pelicula.h"

CAltaPelicula::CAltaPelicula() {}

bool CAltaPelicula::altaPelicula(string titulo, string sinopsis, string url) {
    ManejadorPelicula* mp = ManejadorPelicula::getInstancia();
    Pelicula* pe = mp->buscarPelicula(titulo);
    if (pe != NULL) {
        // Ya existe una película con ese título
        return false;
    }
    // Initialize with 0.0 as the default average rating for a new movie
    Pelicula* p = new Pelicula(titulo, sinopsis, 0.0, url);
    mp->agregarPelicula(p);
    return true;
}

CAltaPelicula::~CAltaPelicula() {}
