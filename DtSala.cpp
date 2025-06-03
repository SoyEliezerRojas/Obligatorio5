#include "DtSala.h"

DtSala::DtSala() {}

DtSala::DtSala(int sala, int cap) {
    this->sala = sala;
    this->capacidad = cap;
}

int DtSala::getSala() {
    return this->sala;
}

int DtSala::getCapacidad() {
    return this->capacidad;
}

list<DtFuncion*> DtSala::getDtFuncion() {
    list<DtFuncion*> lista;
    for (auto& it : funciones) {
        lista.push_back(it.second);
    }
    return lista;
}

DtSala::~DtSala() {}

ostream& operator <<(ostream& salida, const DtSala& dts) {
    salida << "Sala: " << dts.sala << "\n";
    salida << "Capacidad: " << dts.capacidad << "\n";
    return salida;
}