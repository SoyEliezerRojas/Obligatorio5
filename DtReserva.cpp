#include "DtReserva.h"
#include <iostream>

DtReserva::DtReserva() {}

DtReserva::DtReserva(float costo, int cantEnt) {
    this->costo = costo;
    this->cantEntradas = cantEnt;
}

float DtReserva::getCosto() {
    return this->costo;
}

int DtReserva::getCantEntradas() {
    return this->cantEntradas;
}

DtReserva::~DtReserva() {}