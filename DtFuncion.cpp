#include "DtFuncion.h"
#include "DtFecha.h"
#include "DtHorario.h"

DtFuncion::DtFuncion() {}

DtFuncion::DtFuncion(int id, DtFecha fecha, DtHorario hora){
    this->idFun     = id;
    this->dia       = fecha;
    this->horario   = hora;
}

int DtFuncion::getIdFun(){
    return this->idFun; 
}

DtFecha DtFuncion::getDiaFun(){
    return this->dia;
}

DtHorario DtFuncion::getHoraFun(){
    return this->horario;
}

DtFuncion::~DtFuncion() {}