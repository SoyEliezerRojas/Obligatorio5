#ifndef DTSALA_H
#define DTSALA_H

#include <string>
#include <iostream>

using namespace std;

class DtSala {
private:
    int id;
    int capacidad;

public:
    DtSala();
    DtSala(int id, int capacidad);
    int getId();
    int getCapacidad();
    ~DtSala();

    friend ostream& operator <<(ostream&, const DtSala&);
};

#endif