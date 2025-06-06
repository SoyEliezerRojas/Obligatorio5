#ifndef FABRICA_H
#define FABRICA_H

#include "ICIniciarSesion.h"
#include "ICCerrarSesion.h"
#include "ICAltaUsuario.h"
#include "ICAltaPelicula.h"
#include "ICAltaCine.h"

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
    ~Fabrica();
};

#endif // FABRICA_H