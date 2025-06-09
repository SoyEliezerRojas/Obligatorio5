#ifndef MANEJADORPELICULA_H
#define MANEJADORPELICULA_H

#include <list>
#include <map>
#include <string>
#include "Pelicula.h"
#include "DtPelicula.h"

using namespace std;

class ManejadorPelicula {
private:
    static ManejadorPelicula* instancia;
    map<string, Pelicula*> peliculas;
    ManejadorPelicula();

public:
    static ManejadorPelicula* getInstancia();
    void agregarPelicula(Pelicula* pelicula);
    Pelicula* buscarPelicula(string titulo);
    list<DtPelicula> listarPeliculas();
    Pelicula* obtenerPelicula(string titulo);
    ~ManejadorPelicula();
};

#endif
