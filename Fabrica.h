#ifndef FABRICA_H
#define FABRICA_H

#include "ICAltaCine.h"
#include "ICAltaFuncion.h"
#include "ICAltaPelicula.h"
#include "ICCerrarSesion.h"
#include "ICIniciarSesion.h"
#include "ICPuntuarPelicula.h"
#include "ICAltaUsuario.h"
#include "ICCrearReserva.h"
#include "ICComentarPelicula.h"
#include "ICEliminarPelicula.h"

class Fabrica {
private:
    static Fabrica* instancia;
    Fabrica();

public:
    static Fabrica* getInstancia();
    ICAltaCine* getICAltaCine();
    ICAltaFuncion* getICAltaFuncion();
    ICAltaPelicula* getICAltaPelicula();
    ICCerrarSesion* getICCerrarSesion();
    ICIniciarSesion* getICIniciarSesion();
    ICPuntuarPelicula* getICPuntuarPelicula();
    ICAltaUsuario* getICAltaUsuario();
    ICCrearReserva* getICCrearReserva();
    ICComentarPelicula* getICComentarPelicula();
    ICEliminarPelicula* getICEliminarPelicula();
    ~Fabrica();
};

#endif // FABRICA_H