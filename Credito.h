#ifndef CREDITO_H
#define CREDITO_H
#include <iostream>
#include <string>
#include "Reserva.h"

using namespace std;
class Credito: public Reserva{
private:
    float porcDescuento;
    string financiera;
public:
    Credito();
    Credito(int id, float costo, int cantEntradas, float porcDescuento, string financiera);
    float getPorcentaje();
    void setPorcentaje(float);
    string getFinanciera();
    void setFinanciera(string);
    ~Credito();
};
#endif