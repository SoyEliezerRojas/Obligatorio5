#ifndef ICRELOJ_H
#define ICRELOJ_H

#include <string>
#include <iostream>
using namespace std;

class ICReloj {
public:
    virtual bool hayUsuarioLogueado() = 0;
    virtual void modificarFecha(string fechaHora) = 0;
    virtual string consultarFecha() = 0;
    virtual ~ICReloj() {}
};

#endif 