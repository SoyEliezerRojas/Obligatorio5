#include "DtCine.h"
#include <iostream>
#include namespace std

DtCine::DtCine(){}
DtCine::DtCine(int id, DtCine Cine){
	this->id=id;
	this->Direccion=Direccion;
}
string DtCine::getid(){
	return this->id;
}
string DtCine::getDireccion(){
	return this->Direccion;
}

DtCine::~DtCine(){}

ostream& operator <<(ostream& salida, const DtCine& dtc){
    cout << "Id: " << dtc.id << "\n" ;
        "Direccion: " << dtc.Direccion << "\n";
    return salida;
}