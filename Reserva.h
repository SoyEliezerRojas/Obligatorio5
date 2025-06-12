#ifndef RESERVA_H
#define RESERVA_H
#include <string>
#include <iostream>

using namespace std;

class Reserva{
private:
    int id;
    float costo;
    int cantEntradas;
    string formaPago;
public:
    Reserva();
    Reserva(int id, float costo, int cantEntradas, string formaPago);
    int getId();
    float getCosto();
    void setCosto(float);
    int getCantEntradas();
    void setCantEntradas(int);
    string getFormaPago();
    void setFormaPago(string);
    ~Reserva();
};

#endif