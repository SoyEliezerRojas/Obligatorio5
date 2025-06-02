#include "DtHorario.h"
#include <iostream>
using namespace std;

DtHorario::DtHorario(){}

DtHorario::DtHorario(string hIni, string hFin){
    this->horaIni = hIni;
	this->horaFin = hFin;
}

string DtHorario::getHoraIni(){
    return this->horaIni;
}

string DtHorario::getHoraFin(){
    return this->horaIni;
}

DtHorario::~DtHorario(){}

bool operator <(const DtHorario& dth1,const DtHorario& dth2){
	bool retorno;
	if (dth1.horaIni < dth2.horaIni){
		retorno=true;
    } else {
        retorno=false;
        }		
    
	return retorno;
}