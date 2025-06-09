#ifndef FABRICA_H
#define FABRICA_H

#include "ICAltaCine.h"
#include "ICAltaFuncion.h"
#include "ICAltaPelicula.h"
#include "ICCerrarSesion.h"
#include "ICIniciarSesion.h"
#include "ICPuntuarPelicula.h"
#include "ICAltaUsuario.h"
#include "ICComentarPelicula.h"

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
    ICComentarPelicula* getICComentarPelicula();
    ~Fabrica();
};

#endif // FABRICA_H