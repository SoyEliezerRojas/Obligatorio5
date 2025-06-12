#include "Credito.h"

#include<string>

using namespace std;

Credito::Credito(){}

Credito::Credito(int id, float costo, int cantEntradas, float porcentaje, string financiera):Reserva(id, costo, cantEntradas, "Credito"){
    this->porcDescuento = porcentaje;
    this->financiera = financiera;
}

float Credito::getPorcentaje(){
    return this->porcDescuento;
}
void Credito::setPorcentaje(float porcDesc){
    this->porcDescuento = porcDesc;
}
string Credito::getFinanciera(){
    return this->financiera;
}
void Credito::setFinanciera(string financiera){
    this->financiera = financiera;
}

Credito::~Credito(){}