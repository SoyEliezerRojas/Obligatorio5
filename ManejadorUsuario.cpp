#include "Usuario.h"
#include <list>
#include "ManejadorUsuario.h"
using namespace std;

ManejadorUsuario* ManejadorUsuario::instancia = nullptr;

ManejadorUsuario::ManejadorUsuario() {
    this->usuarioActual = nullptr;
}

ManejadorUsuario* ManejadorUsuario::getInstancia() {
    if (instancia == nullptr)
        instancia = new ManejadorUsuario();
    return instancia;
}

list<Usuario*> ManejadorUsuario::getUsuarios() {
    list<Usuario*> lstUsuarios;
    for (map<string, Usuario*>::iterator it = this->usuarios.begin(); it != usuarios.end(); ++it)
        lstUsuarios.push_back(it->second);
    return lstUsuarios;
}

Usuario* ManejadorUsuario::buscarUsuario(string nickname) {
    if (usuarios.count(nickname) > 0)
        return usuarios[nickname];
    return nullptr;
}

void ManejadorUsuario::agregarUsuario(Usuario* usuario) {
    usuarios[usuario->getNickName()] = usuario;
}

bool ManejadorUsuario::existeUsuario(string usuario) {
    map<string, Usuario*>::iterator it = this->usuarios.find(usuario);
    return (it != this->usuarios.end());
}

void ManejadorUsuario::eliminarUsuario(string usuario) {
    map<string, Usuario*>::iterator it = this->usuarios.find(usuario);
    this->usuarios.erase(it);
}

Usuario* ManejadorUsuario::getUsuarioActual() {
    return this->usuarioActual;
}

void ManejadorUsuario::setUsuarioActual(Usuario* usuario) {
    this->usuarioActual = usuario;
}

ManejadorUsuario::~ManejadorUsuario() {
    for (map<string, Usuario*>::iterator it = usuarios.begin(); it != usuarios.end(); ++it) {
        delete it->second;
    }
    usuarios.clear();
}