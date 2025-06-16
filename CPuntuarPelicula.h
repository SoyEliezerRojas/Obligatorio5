#ifndef CPUNTUARPELICULA_H
#define CPUNTUARPELICULA_H

#include "ICPuntuarPelicula.h"
#include "Pelicula.h"
#include "Usuario.h"
#include "DtPelicula.h"

class CPuntuarPelicula : public ICPuntuarPelicula {
private:
    Pelicula* pelicula;
    Usuario* usuario;
    float puntajeTemp;
    bool puntajeConfirmado;

public:
    CPuntuarPelicula();
    list<DtPelicula> listarPeliculas();
    void ingresarPelicula(string titulo);
    void ingresarPuntaje(float puntaje);
    void confirmarPuntaje();
    void cancelarPuntaje();
    bool getPuntajeAnterior(float& puntaje);
    ~CPuntuarPelicula();
};

#endif
