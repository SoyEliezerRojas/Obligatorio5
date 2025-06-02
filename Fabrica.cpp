#include "Fabrica.h"
#include "Controlador.h"
Fabrica* Fabrica::instancia = NULL;

Fabrica::Fabrica(){}

Fabrica* Fabrica::getInstancia(){
    if (instancia == NULL) 
        instancia = new Fabrica();
    return instancia;
}

IControlador* Fabrica::getIControlador(){
    return new Controlador();    
}

Fabrica::~Fabrica(){}

