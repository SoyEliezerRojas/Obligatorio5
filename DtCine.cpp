#include "DtCine.h"
#include <iostream>
using namespace std;

DtCine::DtCine() {}

DtCine::DtCine(int id, DtDireccion dir) {
    this->id = id;
    this->direccion = dir;
}

int DtCine::getid() {
    return this->id;
}

DtDireccion DtCine::getDireccion() {
    return this->direccion;
}

DtCine::~DtCine() {}

ostream& operator <<(ostream& salida, const DtCine& dtc) {
    salida << "Id: " << dtc.id << "\n";
    salida << "Direccion: " << dtc.direccion << "\n";
    return salida;
}