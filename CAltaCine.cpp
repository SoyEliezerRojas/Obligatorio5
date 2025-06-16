#include "CAltaCine.h"
#include "Sesion.h"
#include "ManejadorCine.h"
#include "Cine.h"
#include <iostream>
#include <list>
#include <string>

using namespace std;

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
    // Siguiendo el diagrama de comunicación respetando UML:
    
    // 1. c:=crear(dir) - Crear el cine con ID autogenerado y dirección
    int idAutogenerado = ManejadorCine::getInstancia()->getNextId();
    Cine* c = new Cine(idAutogenerado, this->direccion);
    
    // 2. agregarSalas(capacidades:Set(int)) - Delegar creación de salas a Cine
    // CAltaCine NO puede ver Sala, pero Cine SÍ puede según UML
    c->crearSalasConCapacidades(this->capacidades);
    
    // 3. add() - Agregar el cine al manejador
    ManejadorCine::getInstancia()->agregarCine(c);
}

void CAltaCine::finalizar() {
    // Según diagrama de secuencia: Se libera la memoria asociada a capacidades y dirección
    // En C++, para tipos básicos como DtDireccion y list<int>, 
    // la limpieza se hace automáticamente al salir del scope
    this->capacidades.clear();
    // this->direccion se limpia automáticamente (es un objeto por valor)
}

bool CAltaCine::hayUsuarioLogueado() {
    return Sesion::getInstancia()->getUsuario() != nullptr;
}
