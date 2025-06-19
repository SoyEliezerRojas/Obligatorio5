#ifndef RELOJ_H
#define RELOJ_H

#include <string>
#include <iostream>
#include "DtFecha.h"
#include "DtHorario.h"
using namespace std;

class Reloj {
private:
    static Reloj* instancia;
    DtFecha fechaActual;
    string horaActual; // Formato "hh:mm"
    bool fechaModificadaManualmente; // Flag para saber si el usuario modificó la fecha
    
    Reloj(); // Constructor privado
    void obtenerFechaHoraSistema();
    
public:
    static Reloj* getInstancia();
    void modificarFechaHora(DtFecha fecha, string hora);
    DtFecha getFechaActual();
    string getHoraActual();
    string getFechaHoraFormateada();
    ~Reloj();
};

#endif 