#ifndef FABRICA_H
#define FABRICA_H

#include "ICIniciarSesion.h"
#include "ICCerrarSesion.h"
#include "ICAltaUsuario.h"
#include "ICAltaPelicula.h"
#include "ICAltaCine.h"
#include "ICAltaFuncion.h"

class Fabrica {
private:
    static Fabrica* instancia;
    Fabrica();

public:
    static Fabrica* getInstancia();
    ICIniciarSesion* getICIniciarSesion();
    ICCerrarSesion* getICCerrarSesion();
    ICAltaUsuario* getICAltaUsuario();
    ICAltaPelicula* getICAltaPelicula();
    ICAltaCine* getICAltaCine();
    ICAltaFuncion* getICAltaFuncion();
    ~Fabrica();
};

#endif // FABRICA_H