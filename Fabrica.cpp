#include "Fabrica.h"
#include "CIniciarSesion.h"
#include "CCerrarSesion.h"
#include "CAltaUsuario.h"
#include "CAltaPelicula.h"
#include "CAltaCine.h"
#include "CAltaFuncion.h"
#include "CPuntuarPelicula.h"
#include "CCrearReserva.h"
#include "CComentarPelicula.h"
#include "CEliminarPelicula.h"
#include "CVerReservasDePelicula.h"
#include "CVerInformacionPelicula.h"

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

ICCrearReserva* Fabrica::getICCrearReserva() {
    return new CCrearReserva();
}

ICComentarPelicula* Fabrica::getICComentarPelicula() {
    return new CComentarPelicula();
}

ICEliminarPelicula* Fabrica::getICEliminarPelicula() {
    return new CEliminarPelicula();
}

ICVerReservasDePelicula* Fabrica::getICVerReservasDePelicula() {
    return CVerReservasDePelicula::getInstancia();
}

ICVerInformacionPelicula* Fabrica::getICVerInformacionPelicula() {
    return new CVerInformacionPelicula();
}

Fabrica::~Fabrica() {
    // No hacemos nada aquí ya que la instancia se limpiará automáticamente
    // cuando el programa termine
}