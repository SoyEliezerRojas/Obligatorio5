#include "ManejadorCine.h"

ManejadorCine* ManejadorCine::instancia = NULL;

ManejadorCine::ManejadorCine() {}

ManejadorCine* ManejadorCine::getInstancia() {
    if (instancia == NULL)
        instancia = new ManejadorCine();
    return instancia;
}

void ManejadorCine::agregarCine(Cine* cine) {
    cines.insert(std::pair<int,Cine*>(cine->getIdCine(), cine));
}

Cine* ManejadorCine::buscarCine(int id) {
    map<int,Cine*>::iterator it = this->cines.find(id);
    if (it != this->cines.end()) {
        return it->second;
    }
    return NULL;
}

list<Cine*> ManejadorCine::getCines() {
    list<Cine*> listaCines;
    for (map<int,Cine*>::iterator it = this->cines.begin(); it != cines.end(); ++it)
        listaCines.push_back(it->second);
    return listaCines;
}

bool ManejadorCine::existeCine(int id) {
    map<int,Cine*>::iterator it = this->cines.find(id);
    return (it != this->cines.end());
}

int ManejadorCine::getNextId() {
    if (cines.empty()) {
        return 1;
    }
    // Como es un map, el último elemento tendrá el ID más alto
    return (--cines.end())->first + 1;
}

ManejadorCine::~ManejadorCine() {
    // Liberar memoria de todos los cines
    for (map<int,Cine*>::iterator it = this->cines.begin(); it != cines.end(); ++it) {
        delete it->second;
    }
    cines.clear();
}
