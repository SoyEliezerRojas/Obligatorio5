#ifndef DTCINE_H
#define DTCINE_H
#include "DtSala.h"
#include <string>
using namespace std;

class DtCine {
private:
    int id;
    Dtdireccion direccion;
public:
    DtCine();
    DtCine(int, DtDireccion);
    int getid();
    string getsinopsis();
    DtDireccion getDireccion();
    ~DtCine();

    friend ostream& operator <<(ostream&,const DtFecha&);
};
#endif