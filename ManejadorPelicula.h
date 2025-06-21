#ifndef MANEJADORPELICULA_H
#define MANEJADORPELICULA_H

#include <string>
#include <vector>
#include <list>
#include "Pelicula.h"
#include "DtPelicula.h"
#include "Puntaje.h"

using namespace std;

class ManejadorPelicula {
private:
    static ManejadorPelicula* instancia;
    vector<Pelicula*> peliculas;
    list<Puntaje*> puntajes;
    ManejadorPelicula() {}

public:
    static ManejadorPelicula* getInstancia();
    void agregarPelicula(Pelicula* pelicula);
    void agregarPuntaje(Puntaje* puntaje);
    Pelicula* buscarPelicula(string titulo);
    vector<Pelicula*>& getPeliculas() { return peliculas; }
    list<Puntaje*>& getPuntajes() { return puntajes; }
    list<DtPelicula> listarPeliculas();
    Pelicula* obtenerPelicula(string titulo);
    bool eliminarPelicula(string titulo);
    ~ManejadorPelicula();
};

#endif
