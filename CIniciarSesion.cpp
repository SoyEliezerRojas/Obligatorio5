#include "CIniciarSesion.h"
#include "ManejadorUsuario.h"
#include "Sesion.h"

CIniciarSesion::CIniciarSesion() {}

void CIniciarSesion::ingresarNick(string nick) {
    this->nickname = nick;
}

bool CIniciarSesion::verificarPass(string pass) {
    Usuario* u = ManejadorUsuario::getInstancia()->buscarUsuario(nickname);
    if (!u) return false;
    return u->verificarPass(pass);
}

void CIniciarSesion::iniciarSesion() {
    Usuario* u = ManejadorUsuario::getInstancia()->buscarUsuario(nickname);
    if (u) {
        Sesion::getInstancia()->setUsuario(u);
    }
}

bool CIniciarSesion::iniciarSesion(string& nickname, string& password) {
    this->ingresarNick(nickname);
    if (this->verificarPass(password)) {
        this->iniciarSesion();
        return true;
    }
    return false;
}

CIniciarSesion::~CIniciarSesion() {}
