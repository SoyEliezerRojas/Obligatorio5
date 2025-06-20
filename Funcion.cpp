#include "Funcion.h"
#include "DtFecha.h"
#include "DtHorario.h"
#include "Pelicula.h"
#include "Sala.h"

Funcion::Funcion() {
    this->pelicula = NULL;
    this->sala = NULL;
    this->precio = 0;
}

Funcion::Funcion(int id, DtFecha fecha, DtHorario hora, Sala* sala) {
    this->idFun     = id;
    this->dia       = fecha;
    this->horario   = hora;
    this->pelicula  = NULL;
    this->sala = sala;
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

Sala* Funcion::getSala() {
    return this->sala;
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

list<DtReserva> Funcion::listarReservas() {
    list<DtReserva> dtReservas;
    for (list<Reserva*>::iterator it = reservas.begin(); it != reservas.end(); ++it) {
        dtReservas.push_back(DtReserva((*it)->getId(), (*it)->getCosto(), (*it)->getCantEntradas(), (*it)->getFormaPago()));
    }
    return dtReservas;
}

string Funcion::getTituloPelicula() {
    if (pelicula != NULL) {
        return pelicula->getTitulo();
    }
    return "";
}

Funcion::~Funcion() {
    // No eliminamos las reservas ya que son manejadas por el usuario
    this->reservas.clear();
}