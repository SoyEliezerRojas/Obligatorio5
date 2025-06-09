#ifndef ICPUNTUARPELICULA_H
#define ICPUNTUARPELICULA_H

#include <string>
using namespace std;

class ICPuntuarPelicula {
    public:
        virtual void ingresarPelicula(string titulo) = 0;
        virtual void ingresarPuntaje(float puntaje) = 0;
        virtual void confirmarPuntaje() = 0;
        virtual void cancelarPuntaje() = 0;
        virtual bool getPuntajeAnterior(float& puntaje) = 0;
        virtual ~ICPuntuarPelicula() {}
};

#endif
