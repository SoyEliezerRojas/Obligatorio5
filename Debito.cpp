#include "Debito.h"

Debito::Debito(){}

Debito::Debito(int id, float costo, int cantEntradas, string banco):Reserva(id, costo, cantEntradas, "Debito"){
    this->banco = banco;
}

string Debito::getBanco(){
    return this->banco;
}

void Debito::setBanco(string banco){
    this->banco = banco;
}

Debito::~Debito() {}
