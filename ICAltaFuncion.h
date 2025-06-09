#ifndef ICALTAFUNCION_H
#define ICALTAFUNCION_H

#include <string>
#include <list>
#include "DtPelicula.h"
#include "DtCine.h"
#include "DtSala.h"
#include "DtFecha.h"

using namespace std;

class ICAltaFuncion {
public:
    virtual list<DtPelicula> listarPeliculas() = 0;
    virtual void selectPeli(string titulo) = 0;
    virtual list<DtCine> listarCines() = 0;
    virtual void selectCine(string id) = 0;
    virtual list<DtSala> listarSalas() = 0;
    virtual void selectSala(int id) = 0;
    virtual void altaFuncion(string horaInicio, DtFecha fecha) = 0;
    virtual ~ICAltaFuncion() {}
};

#endif
