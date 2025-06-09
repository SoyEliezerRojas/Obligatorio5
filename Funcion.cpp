#include "Funcion.h"
#include "DtFecha.h"
#include "DtHorario.h"
#include "Pelicula.h"

Funcion::Funcion() {
    this->pelicula = NULL;
    this->precio = 0;
}

Funcion::Funcion(int id, DtFecha fecha, DtHorario hora){
    this->idFun     = id;
    this->dia       = fecha;
    this->horario   = hora;
    this->pelicula  = NULL;
    this->precio    = 0;
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

Pelicula* Funcion::getPelicula() {
    return this->pelicula;
}

void Funcion::setPelicula(Pelicula* p) {
    this->pelicula = p;
}

float Funcion::getPrecio() {
    return this->precio;
}

void Funcion::setPrecio(float p) {
    this->precio = p;
}

void Funcion::agregarReserva(Reserva* r) {
    this->reservas.push_back(r);
}

list<Reserva*> Funcion::getReservas() {
    return this->reservas;
}

Funcion::~Funcion() {
    // No eliminamos las reservas ya que son manejadas por el usuario
    this->reservas.clear();
}