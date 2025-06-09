#ifndef SALA_H
#define SALA_H

#include <iostream>
#include <list>
#include <string>

using namespace std;

// Forward declaration
class Funcion;

class Sala {
private:
    int id;
    int capacidad;
    std::list<Funcion*> funciones;

public:
    Sala();
    Sala(int id, int capacidad);
    int getId();
    void setId(int id);

    int getCapacidad();
    void setCapacidad(int capacidad);

    void agregarFuncion(Funcion* funcion);
    std::list<Funcion*> getFunciones();

    ~Sala();
};

#endif



