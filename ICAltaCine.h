#ifndef ICALTACINE_H
#define ICALTACINE_H

#include <string>
#include <list>
#include "DtDireccion.h"

using namespace std;

class ICAltaCine {
public:
    virtual int getNextId() = 0;
    virtual void ingresarDireccion(DtDireccion direccion) = 0;
    virtual void ingresarCapacidades(list<int> capacidades) = 0;
    virtual void altaCine() = 0;
    virtual ~ICAltaCine() {}
};

#endif
