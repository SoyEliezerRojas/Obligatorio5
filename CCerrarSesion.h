#ifndef CCERRARSESION_H
#define CCERRARSESION_H

#include "Sesion.h"
#include "ICCerrarSesion.h"

class CCerrarSesion : public ICCerrarSesion {
public:
    CCerrarSesion();
    bool cerrarSesion();
    ~CCerrarSesion();
};

#endif // CCERRARSESION_H
