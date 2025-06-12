#include "Reserva.h"
#include <iostream>

Reserva::Reserva() {}

Reserva::Reserva(int id, float costo, int cantEnt, string formaPago) {
    this->id = id;
    this->costo = costo;
    this->cantEntradas = cantEnt;
    this->formaPago = formaPago;
}

int Reserva::getId() {
    return this->id;
}

float Reserva::getCosto() {
    return this->costo;
}

void Reserva::setCosto(float costo) {
    this->costo = costo;
}

int Reserva::getCantEntradas() {
    return this->cantEntradas;
}

void Reserva::setCantEntradas(int cantE) {
    this->cantEntradas = cantE;
}

string Reserva::getFormaPago() {
    return this->formaPago;
}

void Reserva::setFormaPago(string formaPago) {
    this->formaPago = formaPago;
}

Reserva::~Reserva() {}