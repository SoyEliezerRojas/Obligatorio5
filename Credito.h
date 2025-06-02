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
    Credito(float,int,float,string);
    float getPorcentaje();
    void setPorcentaje(float);
    string getFinanciera();
    void setFinanciera(string);
    ~Credito();
};
#endif