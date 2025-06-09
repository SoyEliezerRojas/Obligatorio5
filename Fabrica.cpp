#include "Fabrica.h"
#include "CIniciarSesion.h"
#include "CCerrarSesion.h"
#include "CAltaUsuario.h"
#include "CAltaPelicula.h"
#include "CAltaCine.h"
#include "CAltaFuncion.h"
#include "CPuntuarPelicula.h"
#include "CComentarPelicula.h"

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

ICPuntuarPelicula* Fabrica::getICPuntuarPelicula() {
    return new CPuntuarPelicula();
}

ICComentarPelicula* Fabrica::getICComentarPelicula() {
    return new CComentarPelicula();
}

Fabrica::~Fabrica() {
    // No hacemos nada aquí ya que la instancia se limpiará automáticamente
    // cuando el programa termine
}