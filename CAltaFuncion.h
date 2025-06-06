#ifndef CALTAFUNCION_H
#define CALTAFUNCION_H

#include "ICAltaFuncion.h"
#include "ManejadorPelicula.h"
#include "ManejadorCine.h"
#include "ManejadorFuncion.h"
#include "Pelicula.h"
#include "Cine.h"
#include "Sala.h"
#include "Funcion.h"
#include "DtFecha.h"
#include "DtHorario.h"
#include "DtPelicula.h"
#include "DtCine.h"
#include "DtSala.h"

class CAltaFuncion : public ICAltaFuncion {
private:
    Pelicula* peliculaSeleccionada;
    Cine* cineSeleccionado;
    Sala* salaSeleccionada;

public:
    CAltaFuncion();
    list<DtPelicula> listarPeliculas();
    void selectPeli(string titulo);
    list<DtCine> listarCines();
    void selectCine(string id);
    list<DtSala> listarSalas();
    void selectSala(int id);
    void altaFuncion(int id, string horaInicio, DtFecha fecha);
    ~CAltaFuncion();
};

#endif
