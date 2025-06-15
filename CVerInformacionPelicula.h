#ifndef CVERINFORMACIONPELICULA_H
#define CVERINFORMACIONPELICULA_H

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "ManejadorPelicula.h"
#include "ManejadorCine.h"
#include "Pelicula.h"
#include "Cine.h"
#include "DtPelicula.h"
#include "DtDireccion.h"
#include "ICVerInformacionPelicula.h"

using namespace std;

class CVerInformacionPelicula : public ICVerInformacionPelicula {
private:
    ManejadorPelicula* manejadorPelicula;
    ManejadorCine* manejadorCine;
    
    // Métodos auxiliares privados
    void mostrarListaPeliculas();
    void mostrarInformacionPelicula(const string& titulo);
    void mostrarInformacionCines(const string& titulo);
    bool validarOpcionMenu(int opcion, int maxOpciones);
    string obtenerTituloPorIndice(int indice);
    
public:
    CVerInformacionPelicula();
    void ejecutar();
    ~CVerInformacionPelicula();
    void mostrarFuncionesEnCine(const string& titulo, int idCine);
};

#endif