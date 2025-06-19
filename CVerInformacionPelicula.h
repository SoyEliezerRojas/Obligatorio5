#ifndef CVERINFORMACIONPELICULA_H
#define CVERINFORMACIONPELICULA_H

#include <string>
#include <list>
#include <vector>
#include "ManejadorPelicula.h"
#include "ManejadorCine.h"
#include "Pelicula.h"
#include "Cine.h"
#include "DtPelicula.h"
#include "DtCine.h"
#include "DtFuncion.h"
#include "DtDireccion.h"
#include "ICVerInformacionPelicula.h"

using namespace std;

class CVerInformacionPelicula : public ICVerInformacionPelicula {
private:
    ManejadorPelicula* manejadorPelicula;
    ManejadorCine* manejadorCine;
    
public:
    CVerInformacionPelicula();
    list<DtPelicula> listarPeliculas();
    DtPelicula obtenerInformacionPelicula(string titulo);
    list<DtCine> obtenerCinesPelicula(string titulo);
    list<DtFuncion> obtenerFuncionesPeliculaEnCine(string titulo, int idCine);
    bool validarOpcionMenu(int opcion, int maxOpciones);
    string obtenerTituloPorIndice(int indice);
    ~CVerInformacionPelicula();
};

#endif