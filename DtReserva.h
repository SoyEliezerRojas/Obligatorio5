#ifndef DTRESERVA_H
#define DTRESERVA_H
#include <string>
#include <iostream>

class DtReserva{
private:
    float costo;
    int cantEntradas;
public:
    DtReserva();
    DtReserva(float, int);
    float getCosto();
    int getCantEntradas();
    ~DtReserva();
};

#endif