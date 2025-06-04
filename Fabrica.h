#ifndef FABRICA_H
#define FABRICA_H

#include "ICIniciarSesion.h"
#include "ICCerrarSesion.h"

class Fabrica {
    private:
        static Fabrica* instancia;
        Fabrica();

    public:
        static Fabrica* getInstancia();
    ICIniciarSesion* getICIniciarSesion();
    ICCerrarSesion* getICCerrarSesion();
        ~Fabrica();
};

#endif // FABRICA_H
