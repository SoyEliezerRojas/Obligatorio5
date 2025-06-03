#ifndef DTFUNCION_H
#define DTFUNCION_H

#include <iostream>
#include "DtHorario.h"
#include "DtFecha.h"

class DtFuncion {
private:
    int idFun;
    DtFecha dia;
    DtHorario horario;
public:
    DtFuncion();
    DtFuncion(int, DtFecha, DtHorario);
    int getIdFun();
    DtFecha getDiaFun();
    DtHorario getHoraFun();
    ~DtFuncion();
};

#endif