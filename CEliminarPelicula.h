#ifndef CELIMINARPELICULA_H
#define CELIMINARPELICULA_H

#include "ICEliminarPelicula.h"
#include "ManejadorPelicula.h"
#include "ManejadorFuncion.h"
#include "Sesion.h"
#include "Usuario.h"
#include "Pelicula.h"
#include "DtPelicula.h"
#include <list>
#include <string>

using namespace std;

class CEliminarPelicula : public ICEliminarPelicula {
private:
    ManejadorPelicula* manejadorPelicula;
    ManejadorFuncion* manejadorFuncion;
    Sesion* sesion;
    
public:
    CEliminarPelicula();
    
    // Métodos de la interfaz
    list<DtPelicula> listarPeliculas() override;
    bool eliminarPelicula(string titulo) override;
    
    // Métodos auxiliares
    bool hayUsuarioLogueado();
    DtPelicula obtenerInformacionPelicula(string titulo);
    bool confirmarEliminacion(string titulo);
    void eliminarFuncionesAsociadas(string tituloPelicula);
    
    ~CEliminarPelicula();
};

#endif