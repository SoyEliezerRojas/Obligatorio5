#ifndef ICINICIARSESION_H
#define ICINICIARSESION_H

#include <string>
using namespace std;

class ICIniciarSesion {
public:
    virtual bool iniciarSesion(string& nickname, string& password) = 0;
    virtual ~ICIniciarSesion() {}
};

#endif // ICINICIARSESION_H
