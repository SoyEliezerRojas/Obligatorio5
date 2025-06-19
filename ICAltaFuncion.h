#ifndef ICALTAFUNCION_H
#define ICALTAFUNCION_H

#include <string>
#include <list>
#include <map>
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
    virtual void selectCine(string idCine) = 0;
    virtual list<DtSala> listarSalas() = 0;
    virtual void selectSala(int idSala) = 0;
    virtual void altaFuncion(string horaInicio, DtFecha fecha) = 0;
    virtual bool hayUsuarioLogueado() = 0;
    virtual list<DtSala> obtenerSalasConOcupacion() = 0;
    virtual map<int, string> obtenerInformacionOcupacionSalas() = 0;
    virtual ~ICAltaFuncion() {}
};

#endif
