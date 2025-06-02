#include "DtFecha.h"
DtFecha::DtFecha(){}
DtFecha::DtFecha(int dia,int mes,int anio){
	this->dia=dia;
	this->mes=mes;
	this->anio=anio;
}
int DtFecha::getDia(){
	return this->dia;
}
int DtFecha::getMes(){
	return this->mes;
}
int DtFecha::getAnio(){
	return this->anio;
}
DtFecha::~DtFecha(){}

bool operator <(const DtFecha& dtf1,const DtFecha& dtf2){
	bool retorno;
	if (dtf1.anio < dtf2.anio){
		retorno=true;
	}else if(dtf1.anio == dtf2.anio){
		if (dtf1.mes < dtf2.mes){
			retorno=true;
		}else if(dtf1.mes == dtf2.mes){
			if (dtf1.dia < dtf2.dia){
				retorno=true;
			}else{ 
				retorno=false;
			}
		}
	}
	return retorno;
}
ostream& operator <<(ostream& salida,const DtFecha& dtf){
	cout << dtf.dia << "/" << dtf.mes << "/" << dtf.anio <<endl;
	return salida;
}
