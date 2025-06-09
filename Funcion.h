#ifndef FUNCION_H
#define FUNCION_H
#include <iostream>
#include "DtHorario.h"
#include "DtFecha.h"
#include "Pelicula.h"
#include "Reserva.h"
#include <list>

class Funcion{
private:
    int idFun;
    DtFecha dia;
    DtHorario horario;
    Pelicula* pelicula;
    float precio;
    list<Reserva*> reservas;
public:
    Funcion();
    Funcion(int, DtFecha, DtHorario);
    int getIdFun();
    void setIdFun(int);

    DtFecha getDiaFun();
    void setDiaFun(DtFecha);

    DtHorario getHoraFun();
    void setHorario(DtHorario);

    Pelicula* getPelicula();
    void setPelicula(Pelicula*);

    float getPrecio();
    void setPrecio(float);

    void agregarReserva(Reserva*);
    list<Reserva*> getReservas();

    ~Funcion();
};

#endif