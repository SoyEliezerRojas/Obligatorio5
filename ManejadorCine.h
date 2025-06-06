#ifndef MANEJADORCINE_H
#define MANEJADORCINE_H

#include <map>
#include <list>
#include "Cine.h"

using namespace std;

class ManejadorCine {
private:
    static ManejadorCine* instancia;
    map<int, Cine*> cines;
    ManejadorCine();

public:
    static ManejadorCine* getInstancia();
    void agregarCine(Cine* cine);
    Cine* buscarCine(int id);
    list<Cine*> getCines();
    bool existeCine(int id);
    int getNextId();
    ~ManejadorCine();
};

#endif
