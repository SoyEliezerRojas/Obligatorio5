#ifndef CALTACINE_H
#define CALTACINE_H

#include "ICAltaCine.h"
#include "DtDireccion.h"
#include <list>

using namespace std;

class CAltaCine : public ICAltaCine {
private:
    DtDireccion direccion;
    list<int> capacidades;

public:
    CAltaCine();
    int getNextId();
    void ingresarDireccion(DtDireccion direccion);
    void ingresarCapacidades(list<int> capacidades);
    void altaCine();
    void finalizar();
    bool hayUsuarioLogueado();
};

#endif
