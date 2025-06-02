#include "Reserva.h"
#include <iostream>

Reserva::Reserva() {}

Reserva::Reserva(float costo,int cantEnt){
    this->costo =  costo;
    this->cantEntradas = cantEnt;
}

float Reserva::getCosto(){
    return this->costo;
}

void Reserva::setCosto(float costo){
    this->costo = costo;
}

int Reserva::getCantEntradas(){
    return this->cantEntradas;
}

void Reserva::setCantEntradas(int cantE){
    this->cantEntradas = cantE;
}

Reserva::~Reserva() {}