#include "Credito.h"

#include<string>

using namespace std;

Credito::Credito(){}

Credito::Credito(float costo,int cantEnt, float porcentaje,string financiera):Reserva(costo,cantEnt){
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