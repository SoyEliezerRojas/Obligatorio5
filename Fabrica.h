#ifndef FABRICA_H
#define FABRICA_H

#include "ICIniciarSesion.h"
#include "ICCerrarSesion.h"
#include "ICAltaUsuario.h"

class Fabrica {
private:
    static Fabrica* instancia;
    Fabrica();

public:
    static Fabrica* getInstancia();
    ICIniciarSesion* getICIniciarSesion();
    ICCerrarSesion* getICCerrarSesion();
    ICAltaUsuario* getICAltaUsuario();
    ~Fabrica();
};

#endif // FABRICA_H