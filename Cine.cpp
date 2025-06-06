#include "Cine.h"

Cine::Cine(){}

Cine::Cine(int id, DtDireccion direc){
    this->idCine = id;
    this->direccion = direc;
}

int Cine::getIdCine(){
    return this->idCine;
}

void Cine::setIdCine(int id){
    this->idCine = id;
}

DtDireccion Cine::getDirecCine(){
    return this->direccion;
}

void Cine::setDirecCine(DtDireccion direc){
    this->direccion = direc;
}

void Cine::agregarSala(Sala* sala) {
    this->salas.push_back(sala);
}

list<Sala*> Cine::getSalas() {
    return this->salas;
}

Cine::~Cine() {
    // Liberar memoria de las salas
    for(list<Sala*>::iterator it = salas.begin(); it != salas.end(); ++it) {
        delete *it;
    }
    salas.clear();
}
