#include "CAltaCine.h"
#include "Sesion.h"
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
    // 1. Crear el cine con su dirección
    int nextId = ManejadorCine::getInstancia()->getNextId();
    Cine* c = new Cine(nextId, this->direccion);
    
    // 2. Agregar salas con sus capacidades
    int idSala = 1;
    for (list<int>::iterator it = capacidades.begin(); it != capacidades.end(); ++it) {
        Sala* s = new Sala(idSala, *it);
        c->agregarSala(s);
        idSala++;
    }
    
    // 3. Agregar el cine al manejador
    ManejadorCine::getInstancia()->agregarCine(c);
}

bool CAltaCine::hayUsuarioLogueado() {
    return Sesion::getInstancia()->getUsuario() != NULL;
}
