#ifndef ICVERINFORMACIONPELICULA_H
#define ICVERINFORMACIONPELICULA_H

#include <string>
#include <list>
#include "DtPelicula.h"
#include "DtCine.h"
#include "DtFuncion.h"

using namespace std;

class ICVerInformacionPelicula {
public:
    virtual list<DtPelicula> listarPeliculas() = 0;
    virtual DtPelicula obtenerInformacionPelicula(string titulo) = 0;
    virtual list<DtCine> obtenerCinesPelicula(string titulo) = 0;
    virtual list<DtFuncion> obtenerFuncionesPeliculaEnCine(string titulo, int idCine) = 0;
    virtual bool validarOpcionMenu(int opcion, int maxOpciones) = 0;
    virtual string obtenerTituloPorIndice(int indice) = 0;
    virtual ~ICVerInformacionPelicula() {}
};

#endif
