#ifndef FUNCION_H
#define FUNCION_H
#include <iostream>
#include "DtHorario.h"
#include "DtFecha.h"
#include "DtReserva.h"
#include "Pelicula.h"
#include "Reserva.h"
#include <list>

class Sala; // Forward declaration

class Funcion{
private:
    int idFun;
    DtFecha dia;
    DtHorario horario;
    Pelicula* pelicula;
    Sala* sala;
    float precio;
    list<Reserva*> reservas;
public:
    Funcion();
    Funcion(int, DtFecha, DtHorario, Sala*);
    int getIdFun();
    void setIdFun(int);

    DtFecha getDiaFun();
    void setDiaFun(DtFecha);

    DtHorario getHoraFun();
    void setHorario(DtHorario);

    Sala* getSala();

    Pelicula* getPelicula();
    void setPelicula(Pelicula*);

    float getPrecio();
    void setPrecio(float);

    void agregarReserva(Reserva*);
    list<Reserva*> getReservas();
    list<DtReserva> listarReservas();
    string getTituloPelicula();

    ~Funcion();
};

#endif