#ifndef SALA_H
#define SALA_H
#include <iostream>
#include <list>
#include "Funcion.h"

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
    void setCapacidad(int cap);

    void agregarFuncion(Funcion* funcion);
    list<Funcion*> getFunciones();

    ~Sala();
};

#endif



