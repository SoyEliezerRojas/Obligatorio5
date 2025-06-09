#include "CCerrarSesion.h"
#include "ManejadorUsuario.h"

CCerrarSesion::CCerrarSesion() {}

bool CCerrarSesion::cerrarSesion() {
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    if (mu->getUsuarioActual() != nullptr) {
        mu->setUsuarioActual(nullptr);
        Sesion::getInstancia()->cerrarSesion();
        return true;
    }
    return false;
}

CCerrarSesion::~CCerrarSesion() {}
