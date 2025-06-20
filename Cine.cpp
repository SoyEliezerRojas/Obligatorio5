#include "Cine.h"

Cine::Cine(){}

Cine::Cine(int id, DtDireccion direc){
    this->idCine = id;
    this->direccion = direc;
}

int Cine::getIdCine(){
    return this->idCine;
}

void Cine::setIdCine(int id){
    this->idCine = id;
}

DtDireccion Cine::getDirecCine(){
    return this->direccion;
}

void Cine::setDirecCine(DtDireccion direc){
    this->direccion = direc;
}

void Cine::agregarSala(Sala* sala) {
    this->salas.push_back(sala);
}

list<Sala*> Cine::getSalas() {
    return this->salas;
}

list<DtSala> Cine::getDtSalas() {
    // Método agregado para CAltaFuncion - respeta reglas UML
    // Cine puede ver Sala, por lo que puede crear DtSala
    list<DtSala> dtSalas;
    
    for (list<Sala*>::iterator it = salas.begin(); it != salas.end(); ++it) {
        Sala* sala = *it;
        DtSala dtSala(sala->getId(), sala->getCapacidad());
        dtSalas.push_back(dtSala);
    }
    
    return dtSalas;
}

void Cine::crearSalasConCapacidades(list<int> capacidades) {
    // Cine puede ver Sala según UML, por lo que puede crear salas directamente
    int idSala = 1; // ID autogenerado para salas
    for (list<int>::iterator it = capacidades.begin(); it != capacidades.end(); ++it) {
        Sala* s = new Sala(idSala, *it);
        this->agregarSala(s);
        idSala++;
    }
}

list<DtReserva> Cine::listarReservasDePelicula(string titulo) {
    list<DtReserva> reservas;
    for (list<Sala*>::iterator it = salas.begin(); it != salas.end(); ++it) {
        list<DtReserva> reservasSala = (*it)->listarReservasDePelicula(titulo);
        reservas.insert(reservas.end(), reservasSala.begin(), reservasSala.end());
    }
    return reservas;
}

Cine::~Cine() {
    // Liberar memoria de las salas
    for(list<Sala*>::iterator it = salas.begin(); it != salas.end(); ++it) {
        delete *it;
    }
    salas.clear();
}

Sala* Cine::buscarSala(int idSala) {
    for (Sala* sala : this->salas) {
        if (sala->getId() == idSala) {
            return sala;
        }
    }
    return nullptr; // Si no se encuentra la sala
}
