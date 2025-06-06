#include "ManejadorFuncion.h"

ManejadorFuncion* ManejadorFuncion::instancia = NULL;

ManejadorFuncion::ManejadorFuncion() {}

ManejadorFuncion* ManejadorFuncion::getInstancia() {
    if (instancia == NULL)
        instancia = new ManejadorFuncion();
    return instancia;
}

void ManejadorFuncion::agregarFuncion(Funcion* funcion) {
    funciones.insert(std::pair<int,Funcion*>(funcion->getIdFun(), funcion));
}

Funcion* ManejadorFuncion::buscarFuncion(int id) {
    map<int,Funcion*>::iterator it = this->funciones.find(id);
    if (it != this->funciones.end()) {
        return it->second;
    }
    return NULL;
}

list<Funcion*> ManejadorFuncion::getFunciones() {
    list<Funcion*> listaFunciones;
    for (map<int,Funcion*>::iterator it = this->funciones.begin(); it != funciones.end(); ++it)
        listaFunciones.push_back(it->second);
    return listaFunciones;
}

bool ManejadorFuncion::existeFuncion(int id) {
    map<int,Funcion*>::iterator it = this->funciones.find(id);
    return (it != this->funciones.end());
}

int ManejadorFuncion::getNextId() {
    if (funciones.empty()) {
        return 1;
    }
    return (--funciones.end())->first + 1;
}

ManejadorFuncion::~ManejadorFuncion() {
    // Liberar memoria de todas las funciones
    for (map<int,Funcion*>::iterator it = this->funciones.begin(); it != funciones.end(); ++it) {
        delete it->second;
    }
    funciones.clear();
} 