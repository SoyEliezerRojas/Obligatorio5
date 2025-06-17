#ifndef SALA_H
#define SALA_H

#include <iostream>
#include <list>
#include <string>
#include "DtReserva.h"

using namespace std;

// Forward declaration
class Funcion;

class Sala {
private:
    int id;
    int capacidad;
    list<Funcion*> funciones;

public:
    Sala();
    Sala(int id, int capacidad);
    int getId();
    void setId(int id);

    int getCapacidad();
    void setCapacidad(int capacidad);

    void agregarFuncion(Funcion* funcion);
    list<Funcion*> getFunciones();
    list<DtReserva> listarReservasDePelicula(string titulo);
    void eliminarFuncion(Funcion* funcion);

    ~Sala();
};

#endif



