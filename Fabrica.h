#ifndef FABRICA_H
#define FABRICA_H

#include "ICAltaCine.h"
#include "ICAltaFuncion.h"
#include "ICAltaPelicula.h"
#include "ICCerrarSesion.h"
#include "ICIniciarSesion.h"
#include "ICPuntuarPelicula.h"
#include "ICAltaUsuario.h"
#include "ICCrearReserva.h"
#include "ICComentarPelicula.h"
#include "ICEliminarPelicula.h"
#include "ICVerReservasDePelicula.h"
#include "ICVerInformacionPelicula.h"
#include "ICReloj.h"
#include "ICVerComentariosyPuntajesdePelicula.h"

class Fabrica {
private:
    static Fabrica* instancia;
    Fabrica();

public:
    static Fabrica* getInstancia();
    ICAltaCine* getICAltaCine();
    ICAltaFuncion* getICAltaFuncion();
    ICAltaPelicula* getICAltaPelicula();
    ICCerrarSesion* getICCerrarSesion();
    ICIniciarSesion* getICIniciarSesion();
    ICPuntuarPelicula* getICPuntuarPelicula();
    ICAltaUsuario* getICAltaUsuario();
    ICCrearReserva* getICCrearReserva();
    ICComentarPelicula* getICComentarPelicula();
    ICEliminarPelicula* getICEliminarPelicula();
    ICVerReservasDePelicula* getICVerReservasDePelicula();
    ICVerInformacionPelicula* getICVerInformacionPelicula();
    ICReloj* getICReloj();
    ICVerComentariosyPuntajesdePelicula* getICVerComentariosyPuntajesdePelicula();
    ~Fabrica();
};

#endif // FABRICA_H