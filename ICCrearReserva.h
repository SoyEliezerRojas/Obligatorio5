#ifndef ICCREARRESERVA_H
#define ICCREARRESERVA_H

#include <string>
#include <list>
#include "DtPelicula.h"
#include "DtFuncion.h"

using namespace std;

class ICCrearReserva {
public:
    virtual list<DtPelicula> listarPeliculas() = 0;
    virtual void selectPelicula(string titulo) = 0;
    virtual list<DtFuncion> listarFunciones() = 0;
    virtual void selectFuncion(int id) = 0;
    virtual void ingresarCantidadEntradas(int cantidad) = 0;
    virtual void seleccionarDebito(string banco) = 0;
    virtual void seleccionarCredito(string financiera, float descuento) = 0;
    virtual void confirmarReserva() = 0;
    virtual void cancelarReserva() = 0;
    virtual ~ICCrearReserva() {}
};

#endif
