#include "CCerrarSesion.h"
#include "Sesion.h"

CCerrarSesion::CCerrarSesion() {}

bool CCerrarSesion::cerrarSesion() {
    Sesion* sesion = Sesion::getInstancia();
    if (sesion->getUsuario() != NULL) {
        sesion->setUsuario(NULL);
        return true;
    }
    return false;
}

CCerrarSesion::~CCerrarSesion() {}
