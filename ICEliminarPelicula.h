#ifndef ICELIMINARPELICULA_H
#define ICELIMINARPELICULA_H

#include <string>
#include <list>
#include "DtPelicula.h"

using namespace std;

class ICEliminarPelicula {
public:
    virtual list<DtPelicula> listarPeliculas() = 0;
    virtual bool eliminarPelicula(string titulo) = 0;
    virtual bool hayUsuarioLogueado() = 0;
    virtual DtPelicula obtenerInformacionPelicula(string titulo) = 0;
    virtual ~ICEliminarPelicula() {}
};

#endif