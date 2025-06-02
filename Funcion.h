#ifndef FUNCION_H
#define FUNCION_H
#include <iostream>
#include "DtHorario.h"
#include "DtFecha.h"

class Funcion{
private:
    int idFun;
    DtFecha dia;
    DtHorario horario;
public:
    Funcion();
    Funcion(int, DtFecha, DtHorario);
    int getIdFun();
    void setIdFun(int);

    DtFecha getDiaFun();
    void setDiaFun(DtFecha);

    DtHorario getHoraFun();
    void setHorario(DtHorario);
    ~Funcion();
};

#endif