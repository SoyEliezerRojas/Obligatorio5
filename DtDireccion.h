#ifndef DTDIRECCION_H
#define DTDIRECCION_H

#include <string>
using namespace std;

class DtDireccion {
private:
    string calle;
    int numero;
public:
    DtDireccion();
    DtDireccion(string, int);
    string getCalle();
    int getNumero();
    ~DtDireccion();

    friend ostream& operator << (ostream&, const DtDireccion&);
};
#endif