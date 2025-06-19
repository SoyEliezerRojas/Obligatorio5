#ifndef CRELOJ_H
#define CRELOJ_H

#include "ICReloj.h"
#include "Reloj.h"
#include "Sesion.h"
#include "DtFecha.h"
#include <string>
#include <iostream>
using namespace std;

class CReloj : public ICReloj {
private:
    bool validarFormato(string fechaHora);
    DtFecha parsearFecha(string fechaHora);
    string parsearHora(string fechaHora);
    bool validarFecha(int dia, int mes, int anio);
    bool validarHora(string hora);
    
public:
    CReloj();
    bool hayUsuarioLogueado();
    void modificarFecha(string fechaHora);
    string consultarFecha();
    ~CReloj();
};

#endif 