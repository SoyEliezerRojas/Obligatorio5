#ifndef DEBITO_H
#define DEBITO_H
#include "Reserva.h"
#include <iostream>
#include <string>

using namespace std;

class Debito: public Reserva{
private:
    string banco;
public:
    Debito();
    Debito(float,int,string);
    string getBanco();
    void setBanco(string);
    ~Debito();
};

#endif
