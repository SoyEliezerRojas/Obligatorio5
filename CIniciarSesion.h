#ifndef CINICIARSESION_H
#define CINICIARSESION_H

#include "Sesion.h"
#include "ICIniciarSesion.h"
#include <string>
using namespace std;

class CIniciarSesion : public ICIniciarSesion {
public:
    CIniciarSesion();
    void ingresarNick(string nick);
    bool verificarPas(string pass);
    void iniciarSesion();  // Conecta usuario a sesión (implementa interfaz)
    ~CIniciarSesion();
private:
    string nickname;
};

#endif // CINICIARSESION_H
