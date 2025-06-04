#include "Sesion.h"

Sesion* Sesion::instancia = nullptr;

Sesion::Sesion() : usuarioActual(nullptr) {}

Sesion* Sesion::getInstancia() {
    if (instancia == nullptr) {
        instancia = new Sesion();
    }
    return instancia;
}

void Sesion::setUsuario(Usuario* usuario) {
    usuarioActual = usuario;
}

Usuario* Sesion::getUsuario() {
    return usuarioActual;
}

void Sesion::cerrarSesion() {
    usuarioActual = nullptr;
}

Sesion::~Sesion() {
    if (usuarioActual != nullptr) {
        usuarioActual = nullptr;
    }
}
