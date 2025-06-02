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

Cine::~Cine(){}
