#ifndef MANEJADORUSUARIO_H
#define MANEJADORUSUARIO_H

#include <map>
#include <string>
#include <list>
#include "Usuario.h"

using namespace std;

class ManejadorUsuario {
private:
    static ManejadorUsuario* instancia;
    map<string, Usuario*> usuarios;
    Usuario* usuarioActual;
    ManejadorUsuario();

public:
    static ManejadorUsuario* getInstancia();
    void agregarUsuario(Usuario* usuario);
    Usuario* buscarUsuario(string nickname);
    Usuario* getUsuarioActual();
    void setUsuarioActual(Usuario* usuario);
    list<Usuario*> getUsuarios();
    bool existeUsuario(string usuario);
    void eliminarUsuario(string usuario);
    ~ManejadorUsuario();
};

#endif