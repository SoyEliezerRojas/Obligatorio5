#ifndef DTRESERVA_H
#define DTRESERVA_H
#include <string>
#include <iostream>

using namespace std;

class DtReserva{
private:
    int id;
    float costo;
    int cantEntradas;
    string formaPago;
public:
    DtReserva();
    DtReserva(int id, float costo, int cantEntradas, string formaPago);
    int getId();
    float getCosto();
    int getCantEntradas();
    string getFormaPago();
    ~DtReserva();
};

#endif