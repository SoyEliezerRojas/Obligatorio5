#ifndef PUNTAJE_H
#define PUNTAJE_H

#include "Usuario.h"
#include "DtPuntaje.h"
#include "Pelicula.h"

using namespace std;

class Puntaje {
    private:
        float puntaje;
        Pelicula* pelicula;
        Usuario* usuario;
        
    public:
        Puntaje();
        Puntaje(float puntaje, Pelicula* pelicula, Usuario* usuario);
        float getPuntaje();
        Pelicula* getPelicula();
        Usuario* getUsuario();
        DtPuntaje* getDtPuntaje();
        ~Puntaje();
};

#endif