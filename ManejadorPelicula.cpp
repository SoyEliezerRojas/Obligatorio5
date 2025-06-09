#include "ManejadorPelicula.h"

ManejadorPelicula* ManejadorPelicula::instancia = nullptr;

ManejadorPelicula::ManejadorPelicula() {}

ManejadorPelicula* ManejadorPelicula::getInstancia() {
    if (instancia == nullptr)
        instancia = new ManejadorPelicula();
    return instancia;
}

void ManejadorPelicula::agregarPelicula(Pelicula* pelicula) {
    peliculas[pelicula->getTitulo()] = pelicula;
}

Pelicula* ManejadorPelicula::buscarPelicula(string titulo) {
    if (peliculas.count(titulo) > 0)
        return peliculas[titulo];
    return nullptr;
}

list<DtPelicula> ManejadorPelicula::listarPeliculas() {
    list<DtPelicula> resultado;
    for (map<string, Pelicula*>::iterator it = peliculas.begin(); it != peliculas.end(); ++it) {
        DtPelicula dt(it->second->getTitulo(), it->second->getSinopsis(), it->second->getPoster(), it->second->getPuntajeProm());
        resultado.push_back(dt);
    }
    return resultado;
}

Pelicula* ManejadorPelicula::obtenerPelicula(string titulo) {
    return buscarPelicula(titulo);
}

ManejadorPelicula::~ManejadorPelicula() {
    for (map<string, Pelicula*>::iterator it = peliculas.begin(); it != peliculas.end(); ++it) {
        delete it->second;
    }
    peliculas.clear();
}
