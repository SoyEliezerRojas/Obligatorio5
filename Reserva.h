#ifndef RESERVA_H
#define RESERVA_H
#include <string>
#include <iostream>

class Reserva{
private:
    float costo;
    int cantEntradas;
public:
    Reserva();
    Reserva(float, int);
    float getCosto();
    void setCosto(float);
    int getCantEntradas();
    void setCantEntradas(int);
    ~Reserva();
};

#endif