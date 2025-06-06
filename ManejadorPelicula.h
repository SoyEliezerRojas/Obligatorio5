#ifndef MANEJADORPELICULA_H
#define MANEJADORPELICULA_H

#include <string>
#include <vector>
#include "Pelicula.h"

using namespace std;

class ManejadorPelicula {
private:
    static ManejadorPelicula* instancia;
    ManejadorPelicula() {}

public:
    vector<Pelicula*> peliculas;
    static ManejadorPelicula* getInstancia();
    void agregarPelicula(Pelicula* pelicula);
    Pelicula* buscarPelicula(string titulo);
    vector<Pelicula*>& getPeliculas() { return peliculas; }
    ~ManejadorPelicula();
};

#endif
