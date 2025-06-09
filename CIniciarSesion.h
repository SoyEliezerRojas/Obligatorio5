#ifndef CINICARSESION_H
#define CINICARSESION_H

#include "ICIniciarSesion.h"
#include "Usuario.h"
#include "Sesion.h"
#include <string>

using namespace std;

class CIniciarSesion : public ICIniciarSesion {
private:
    string nickname;
public:
    CIniciarSesion();
    void ingresarNick(string nick);
    bool verificarPass(string pass);
    bool iniciarSesion(string& nickname, string& password);
    void iniciarSesion();
    ~CIniciarSesion();
};

#endif
