#include "DtReserva.h"
#include <iostream>

DtReserva::DtReserva() {}

DtReserva::DtReserva(int id, float costo, int cantEnt, string formaPago) {
    this->id = id;
    this->costo = costo;
    this->cantEntradas = cantEnt;
    this->formaPago = formaPago;
}

int DtReserva::getId() {
    return this->id;
}

float DtReserva::getCosto() {
    return this->costo;
}

int DtReserva::getCantEntradas() {
    return this->cantEntradas;
}

string DtReserva::getFormaPago() {
    return this->formaPago;
}

DtReserva::~DtReserva() {}