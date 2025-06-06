#ifndef CINE_H
#define CINE_H
#include "DtDireccion.h"
#include "Sala.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Cine{
private:
    int idCine;
    DtDireccion direccion;
    list<Sala*> salas;
public:
    Cine();
    Cine(int, DtDireccion);
    int getIdCine();
    void setIdCine(int);

    DtDireccion getDirecCine();
    void setDirecCine(DtDireccion);
    
    void agregarSala(Sala* sala);
    list<Sala*> getSalas();
    
    ~Cine();
};

#endif