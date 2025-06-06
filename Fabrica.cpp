#include "Fabrica.h"
#include "CIniciarSesion.h"
#include "CCerrarSesion.h"
#include "CAltaUsuario.h"
#include "CAltaPelicula.h"
#include "CAltaCine.h"
#include "CAltaFuncion.h"

Fabrica* Fabrica::instancia = nullptr;

Fabrica::Fabrica() {}

Fabrica* Fabrica::getInstancia() {
    if (instancia == nullptr) {
        instancia = new Fabrica();
    }
    return instancia;
}

ICIniciarSesion* Fabrica::getICIniciarSesion() {
    return new CIniciarSesion();
}

ICCerrarSesion* Fabrica::getICCerrarSesion() {
    return new CCerrarSesion();
}

ICAltaUsuario* Fabrica::getICAltaUsuario() {
    return new CAltaUsuario();
}

ICAltaPelicula* Fabrica::getICAltaPelicula() {
    return new CAltaPelicula();
}

ICAltaCine* Fabrica::getICAltaCine() {
    return new CAltaCine();
}

ICAltaFuncion* Fabrica::getICAltaFuncion() {
    return new CAltaFuncion();
}

Fabrica::~Fabrica() {
    if (instancia != nullptr) {
        delete instancia;
        instancia = nullptr;
    }
}