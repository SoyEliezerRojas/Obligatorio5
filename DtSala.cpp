#include "DtSala.h"

DtSala::DtSala() {}

DtSala::DtSala(int id, int cap) {
    this->id = id;
    this->capacidad = cap;
}

int DtSala::getId() {
    return this->id;
}

int DtSala::getCapacidad() {
    return this->capacidad;
}

DtSala::~DtSala() {}

ostream& operator <<(ostream& salida, const DtSala& dts) {
    salida << "Sala: " << dts.id << "\n";
    salida << "Capacidad: " << dts.capacidad << "\n";
    return salida;
}