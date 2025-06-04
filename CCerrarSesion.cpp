#include "CCerrarSesion.h"

CCerrarSesion* CCerrarSesion::instancia = nullptr;

CCerrarSesion::CCerrarSesion() {}

CCerrarSesion* CCerrarSesion::getInstancia() {
    if (instancia == nullptr) {
        instancia = new CCerrarSesion();
    }
    return instancia;
}

void CCerrarSesion::cerrarSesion() {
    Sesion::getInstancia()->cerrarSesion();
}

CCerrarSesion::~CCerrarSesion() {
    if (instancia != nullptr) {
        delete instancia;
        instancia = nullptr;
    }
}
