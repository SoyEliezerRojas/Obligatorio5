#ifndef MANEJADORPELICULA_H
#define MANEJADORPELICULA_H

#include <string>
#include <vector>
#include <list>
#include "Pelicula.h"
#include "DtPelicula.h"

using namespace std;

class ManejadorPelicula {
private:
    static ManejadorPelicula* instancia;
    vector<Pelicula*> peliculas;
    ManejadorPelicula() {}

public:
    static ManejadorPelicula* getInstancia();
    void agregarPelicula(Pelicula* pelicula);
    Pelicula* buscarPelicula(string titulo);
    vector<Pelicula*>& getPeliculas() { return peliculas; }
    list<DtPelicula> listarPeliculas();
    Pelicula* obtenerPelicula(string titulo);
    ~ManejadorPelicula();
};

#endif
