#ifndef ICINICIARSESION_H
#define ICINICIARSESION_H

#include <string>
using namespace std;

class ICIniciarSesion {
public:
    virtual void ingresarNick(string nick) = 0;
    virtual bool verificarPas(string pass) = 0;
    virtual void iniciarSesion() = 0;  // Conecta usuario a sesión
    virtual ~ICIniciarSesion() {}
};

#endif // ICINICIARSESION_H
