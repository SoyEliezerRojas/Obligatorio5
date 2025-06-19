#include "Financiera.h"

Financiera::Financiera() {
    this->nombre = "";
    this->descuento = 0.0;
}

Financiera::Financiera(string nombre, float descuento) {
    this->nombre = nombre;
    this->descuento = descuento;
}

string Financiera::getNombre() {
    return this->nombre;
}

void Financiera::setNombre(string nombre) {
    this->nombre = nombre;
}

float Financiera::getDescuento() {
    return this->descuento;
}

void Financiera::setDescuento(float descuento) {
    this->descuento = descuento;
}

Financiera::~Financiera() {
    // No hay punteros que liberar
} 