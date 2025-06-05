#include "Fabrica.h"
#include "CIniciarSesion.h"
#include "CCerrarSesion.h"
#include "CAltaUsuario.h"

Fabrica* Fabrica::instancia = nullptr;

Fabrica::Fabrica() {}

Fabrica* Fabrica::getInstancia() {
    if (instancia == nullptr) {
        instancia = new Fabrica();
    }
    return instancia;
}

ICIniciarSesion* Fabrica::getICIniciarSesion() {
    return CIniciarSesion::getInstancia();
}

ICCerrarSesion* Fabrica::getICCerrarSesion() {
    return CCerrarSesion::getInstancia();
}

ICAltaUsuario* Fabrica::getICAltaUsuario() {
    return new CAltaUsuario;
}

Fabrica::~Fabrica() {
    if (instancia != nullptr) {
        delete instancia;
        instancia = nullptr;
    }
}