#ifndef ICVERRESERVASDEPELICULA_H
#define ICVERRESERVASDEPELICULA_H

#include <list>
#include <string>
#include "DtPelicula.h"
#include "DtFuncion.h"
#include "DtReserva.h"

class ICVerReservasDePelicula {
public:
    virtual list<DtPelicula> listarPeliculas() = 0;
    virtual void selectPelicula(string titulo) = 0;
    virtual list<DtFuncion> listarFunciones() = 0;
    virtual void selectFuncion(int idFuncion) = 0;
    virtual list<DtReserva> listarReservas() = 0;
    virtual list<DtReserva> listarReservasDePelicula(string titulo) = 0;
    virtual ~ICVerReservasDePelicula() {}
};

#endif
