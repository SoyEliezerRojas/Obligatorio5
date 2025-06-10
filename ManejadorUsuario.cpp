#include "Usuario.h"
#include <list>
#include "ManejadorUsuario.h"
using namespace std;

ManejadorUsuario* ManejadorUsuario::instancia = NULL;

ManejadorUsuario::ManejadorUsuario() {
    this->usuarioActual = nullptr;
}

ManejadorUsuario* ManejadorUsuario::getInstancia() {
    if (instancia == NULL) {
        instancia = new ManejadorUsuario();
    }
    return instancia;
}

list<Usuario*> ManejadorUsuario::getUsuarios() {
    list<Usuario*> lista;
    for (map<string,Usuario*>::iterator it = usuarios.begin(); it != usuarios.end(); ++it) {
        lista.push_back(it->second);
    }
    return lista;
}

Usuario* ManejadorUsuario::buscarUsuario(string nickname) {
    if (usuarios.find(nickname) != usuarios.end()) {
        return usuarios[nickname];
    }
    return nullptr;
}

void ManejadorUsuario::agregarUsuario(Usuario* usuario) {
    usuarios[usuario->getNickName()] = usuario;
}

bool ManejadorUsuario::existeUsuario(string nickname) {
    return usuarios.find(nickname) != usuarios.end();
}

void ManejadorUsuario::eliminarUsuario(string nickname) {
    if (usuarios.find(nickname) != usuarios.end()) {
        delete usuarios[nickname];
        usuarios.erase(nickname);
    }
}

Usuario* ManejadorUsuario::getUsuarioActual() {
    return this->usuarioActual;
}

void ManejadorUsuario::setUsuarioActual(Usuario* usuario) {
    this->usuarioActual = usuario;
}

ManejadorUsuario::~ManejadorUsuario() {
    for (map<string,Usuario*>::iterator it = usuarios.begin(); it != usuarios.end(); ++it) {
        delete it->second;
    }
    usuarios.clear();
}