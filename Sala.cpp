#include "Sala.h"
#include "Funcion.h"

Sala::Sala() {
    this->id = 0;
    this->capacidad = 0;
}

Sala::Sala(int id, int capacidad) {
    this->id = id;
    this->capacidad = capacidad;
}

int Sala::getId() {
    return this->id;
}

void Sala::setId(int id) {
    this->id = id;
}

int Sala::getCapacidad() {
    return this->capacidad;
}

void Sala::setCapacidad(int capacidad) {
    this->capacidad = capacidad;
}

void Sala::agregarFuncion(Funcion* funcion) {
    this->funciones.push_back(funcion);
}

list<Funcion*> Sala::getFunciones() {
    return this->funciones;
}

Sala::~Sala() {
    // No eliminamos las funciones ya que son manejadas por el manejador de funciones
    this->funciones.clear();
}
