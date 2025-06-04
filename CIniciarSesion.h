#ifndef CINICIARSESION_H
#define CINICIARSESION_H

#include "Usuario.h"
#include "Sesion.h"
#include "ICIniciarSesion.h"
#include <string>
using namespace std;

class CIniciarSesion : public ICIniciarSesion {
private:
    static CIniciarSesion* instancia;
    CIniciarSesion();

public:
    static CIniciarSesion* getInstancia();
    bool iniciarSesion(string& nickname, string& password);
    ~CIniciarSesion();
};

#endif // CINICIARSESION_H
