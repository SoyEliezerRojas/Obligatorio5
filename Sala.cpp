#include "Sala.h"

Sala::Sala(){}
Sala::Sala(int sala, int cap){
    this->sala = sala;
    this->capacidad = cap;
}

int Sala::getSala(){
    return this->sala;
}
void Sala::setSala(int sala){
    this->sala = sala;
}

int Sala::getCapacidad(){
    return this->capacidad;
}

void Sala::setCapacidad(int cap){
    this->capacidad = cap;
}
Sala::~Sala(){}
