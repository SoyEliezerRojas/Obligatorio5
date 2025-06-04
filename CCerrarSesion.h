#ifndef CCERRARSESION_H
#define CCERRARSESION_H

#include "Sesion.h"
#include "ICCerrarSesion.h"

class CCerrarSesion : public ICCerrarSesion {
private:
    static CCerrarSesion* instancia;
    CCerrarSesion();

public:
    static CCerrarSesion* getInstancia();
    void cerrarSesion();
    ~CCerrarSesion();
};

#endif // CCERRARSESION_H
