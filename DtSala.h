#ifndef DTSALA_H
#define DTSALA_H

#include <string>
#include <map>
#include <list>
#include <iostream>
#include "DtFuncion.h"  // NECESARIO para que DtFuncion sea conocido

using namespace std;

class DtSala {
private:
    int sala;
    int capacidad;
    map<string, DtFuncion*> funciones;

public:
    DtSala();
    DtSala(int sala, int capacidad);
    int getSala();
    int getCapacidad();
    list<DtFuncion*> getDtFuncion();  // Asumido como getter de funciones
    ~DtSala();

    friend ostream& operator <<(ostream&, const DtSala&);
};

#endif