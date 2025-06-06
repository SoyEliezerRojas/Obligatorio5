#ifndef MANEJADORPELICULA_H
#define MANEJADORPELICULA_H

#include <string>
#include <vector>
#include "Pelicula.h"

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
    ~ManejadorPelicula();
};

#endif
