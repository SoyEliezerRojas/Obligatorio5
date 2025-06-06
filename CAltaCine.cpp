#include "CAltaCine.h"
#include "ManejadorCine.h"
#include "Cine.h"
#include "Sala.h"

CAltaCine::CAltaCine() {}

int CAltaCine::getNextId() {
    return ManejadorCine::getInstancia()->getNextId();
}

void CAltaCine::ingresarDireccion(DtDireccion direccion) {
    this->direccion = direccion;
}

void CAltaCine::ingresarCapacidades(list<int> capacidades) {
    this->capacidades = capacidades;
}

void CAltaCine::altaCine() {
    // 1. Crear el cine con la dirección
    // Obtener el siguiente ID del ManejadorCine
    int nextId = ManejadorCine::getInstancia()->getNextId();
    Cine* c = new Cine(nextId, this->direccion);
    
    // 2. Agregar salas con sus capacidades
    list<int>::iterator it;
    int i = 1; // Contador para el número de sala
    for(it = this->capacidades.begin(); it != this->capacidades.end(); ++it) {
        Sala* s = new Sala(i, *it); // Crear sala con número y capacidad
        c->agregarSala(s); // Agregar sala al cine
        i++;
    }
    
    // 3. Agregar el cine al manejador
    ManejadorCine::getInstancia()->agregarCine(c);
}

CAltaCine::~CAltaCine() {}
