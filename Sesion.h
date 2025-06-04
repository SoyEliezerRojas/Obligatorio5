#ifndef SESION_H
#define SESION_H

#include "Usuario.h"

class Sesion {
private:
    static Sesion* instancia;
    Usuario* usuarioActual;
    
    // Constructor privado (patrón Singleton)
    Sesion();

public:
    static Sesion* getInstancia();
    void setUsuario(Usuario* usuario);
    Usuario* getUsuario();
    void cerrarSesion();
    
    // Destructor
    ~Sesion();
};

#endif // SESION_H
