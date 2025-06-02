#include "Funcion.h"
#include "DtFecha.h"
#include "DtHorario.h"
#include "Pelicula.h"

Funcion::Funcion() {}

Funcion::Funcion(int id, DtFecha fecha, DtHorario hora){
    this->idFun     = id;
    this->dia       = fecha;
    this->horario   = hora;
}

int Funcion::getIdFun(){
    return this->idFun; 
}
void Funcion::setIdFun(int id){
    this->idFun = id;
}

DtFecha Funcion::getDiaFun(){
    return this->dia;
}

void Funcion::setDiaFun(DtFecha dia){
    this->dia = dia;
}

DtHorario Funcion::getHoraFun(){
    return this->horario;
}

void Funcion::setHorario(DtHorario hora){
    this->horario = hora;
}

Funcion::~Funcion() {}