#ifndef MANEJADORFUNCION_H
#define MANEJADORFUNCION_H

#include <map>
#include <list>
#include "Funcion.h"

using namespace std;

class ManejadorFuncion {
private:
    static ManejadorFuncion* instancia;
    map<int, Funcion*> funciones;
    ManejadorFuncion();

public:
    static ManejadorFuncion* getInstancia();
    void agregarFuncion(Funcion* funcion);
    Funcion* buscarFuncion(int id);
    list<Funcion*> getFunciones();
    bool existeFuncion(int id);
    int getNextId();
    ~ManejadorFuncion();
};

#endif 