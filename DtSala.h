#ifndef DTSALA_H
#define DTSALA_H
#include "DtFuncion.h"

class DtSala {
private:
    int id;
    int capacidad;
    map<string,DtFuncion*> funciones;
public:
    DtSala();
    DtSala(int, int, DtFuncion*);
    int getid();
    int getcapacidad();
    list<DtFuncion*> getDtFuncion();
    ~DtSala();

    friend ostream& operator <<(ostream&,const DtSala&);
};
#endif