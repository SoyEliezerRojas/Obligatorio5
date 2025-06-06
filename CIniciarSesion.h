#ifndef CINICIARSESION_H
#define CINICIARSESION_H

#include "Usuario.h"
#include "Sesion.h"
#include "ICIniciarSesion.h"
#include <string>
using namespace std;

class CIniciarSesion : public ICIniciarSesion {
public:
    CIniciarSesion();
    void ingresarNick(string nick);
    bool verificarPass(string pass);
    void iniciarSesion();
    bool iniciarSesion(string& nickname, string& password);
    ~CIniciarSesion();
private:
    string nickname;
};

#endif // CINICIARSESION_H
