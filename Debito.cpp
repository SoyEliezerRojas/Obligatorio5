#include "Debito.h"

Debito::Debito(){}

Debito::Debito(float costo,int cantEnt, string banco):Reserva(costo,cantEnt){
    this->banco = banco;
}

string Debito::getBanco(){
    return this->banco;
}

void Debito::setBanco(string banco){
    this->banco = banco;
}
Debito::~Debito() {}
