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
    virtual list<DtFuncion> obtenerFuncionesDePelicula(string titulo) = 0;
    virtual list<DtReserva> obtenerReservasDeFuncion(int idFuncion) = 0;
    virtual ~ICVerReservasDePelicula() {}
};

#endif
