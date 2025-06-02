#include "DtDireccion.h"
#include <string>
#include<iostream>
using namespace std;
DtDireccion::DtDireccion(){}

DtDireccion::DtDireccion(string calle, int numero){
    this->calle = calle;
    this->numero = numero;
}

string DtDireccion::getCalle(){
    return this->calle;
}

int DtDireccion::getNumero(){
    return this->numero;
}

DtDireccion::~DtDireccion(){}

ostream& operator <<(ostream& salida, const DtDireccion& dtd){
	cout << "Calle: " << dtd.calle << "\n" 
    "Numero: " << dtd.numero << "\n";
	return salida;
}