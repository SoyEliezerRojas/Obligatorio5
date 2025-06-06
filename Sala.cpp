#include "Sala.h"

Sala::Sala(){}
Sala::Sala(int id, int cap){
    this->id = id;
    this->capacidad = cap;
}

int Sala::getId(){
    return this->id;
}
void Sala::setId(int id){
    this->id = id;
}

int Sala::getCapacidad(){
    return this->capacidad;
}

void Sala::setCapacidad(int cap){
    this->capacidad = cap;
}

void Sala::agregarFuncion(Funcion* funcion) {
    this->funciones.push_back(funcion);
}

list<Funcion*> Sala::getFunciones() {
    return this->funciones;
}

Sala::~Sala(){}
