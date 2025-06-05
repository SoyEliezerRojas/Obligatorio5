#include "Puntaje.h"

Puntaje::Puntaje(){}
Puntaje::Puntaje(int pj){
    this->puntaje = pj;
}

int Puntaje::getPuntaje(){
    return this->puntaje;
}

void Puntaje::setPuntaje(int pj){
    this->puntaje = pj;
}

Puntaje::~Puntaje(){}