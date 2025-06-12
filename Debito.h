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
    Debito(int id, float costo, int cantEntradas, string banco);
    string getBanco();
    void setBanco(string);
    ~Debito();
};

#endif
