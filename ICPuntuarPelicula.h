#ifndef ICPUNTUARPELICULA_H
#define ICPUNTUARPELICULA_H

#include <string>
#include <list>
#include "DtPelicula.h"
using namespace std;

class ICPuntuarPelicula {
    public:
        virtual list<DtPelicula> listarPeliculas() = 0;
        virtual void ingresarPelicula(string titulo) = 0;
        virtual void ingresarPuntaje(float puntaje) = 0;
        virtual void confirmarPuntaje() = 0;
        virtual void cancelarPuntaje() = 0;
        virtual bool getPuntajeAnterior(float& puntaje) = 0;
        virtual ~ICPuntuarPelicula() {}
};

#endif
