#ifndef CALTAFUNCION_H
#define CALTAFUNCION_H

#include <string>
#include <list>
#include <map>
#include "ICAltaFuncion.h"
#include "ManejadorPelicula.h"
#include "ManejadorCine.h"
#include "ManejadorFuncion.h"
#include "Pelicula.h"
#include "Cine.h"
#include "Funcion.h"
#include "DtFecha.h"
#include "DtHorario.h"
#include "DtPelicula.h"
#include "DtCine.h"
#include "DtSala.h"

using namespace std;

class CAltaFuncion : public ICAltaFuncion {
private:
    // Atributos para recordar las selecciones del usuario
    string tituloPeliculaSeleccionada;
    string idCineSeleccionado;
    int idSalaSeleccionada;

public:
    CAltaFuncion();
    
    // Implementación de la interfaz siguiendo los diagramas de comunicación
    list<DtPelicula> listarPeliculas();
    void selectPeli(string titulo);
    list<DtCine> listarCines();
    void selectCine(string idCine);
    list<DtSala> listarSalas();
    void selectSala(int idSala);
    void altaFuncion(string horaInicio, DtFecha fecha);
    bool hayUsuarioLogueado();
    
    // Nuevo método para obtener información detallada de salas
    list<DtSala> obtenerSalasConOcupacion();
    map<int, string> obtenerInformacionOcupacionSalas();
    
    ~CAltaFuncion();
};

#endif
