#ifndef CINE_H
#define CINE_H
#include "DtDireccion.h"
#include <iostream>
#include <string>

using namespace std;

class Cine{
private:
    int idCine;
    DtDireccion direccion;
public:
    Cine();
    Cine(int, DtDireccion);
    int getIdCine();
    void setIdCine(int);

    DtDireccion getDirecCine();
    void setDirecCine(DtDireccion);
    ~Cine();

};

#endif