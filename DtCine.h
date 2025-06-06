#ifndef DTCINE_H
#define DTCINE_H

#include "DtSala.h"
#include "DtDireccion.h"
#include "DtFecha.h"
#include <string>
#include <iostream>

using namespace std;

class DtCine {
private:
    int id;
    DtDireccion direccion;
public:
    DtCine();
    DtCine(int, DtDireccion);
    int getId();
    DtDireccion getDireccion();
    ~DtCine();

    friend ostream& operator <<(ostream&, const DtCine&);
};

#endif