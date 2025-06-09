#ifndef PUNTAJE_H
#define PUNTAJE_H

#include "Pelicula.h"
#include "Usuario.h"
#include "DtPuntaje.h"

class Puntaje {
    private:
        float puntaje;
        Pelicula* pelicula;
        Usuario* usuario;
        
    public:
        Puntaje(float puntaje, Pelicula* pelicula, Usuario* usuario);
        float getPuntaje();
        Pelicula* getPelicula();
        Usuario* getUsuario();
        DtPuntaje* getDtPuntaje();
        ~Puntaje();
};

#endif