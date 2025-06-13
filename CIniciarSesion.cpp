#include "CIniciarSesion.h"
#include "ManejadorUsuario.h"
#include "Sesion.h"
#include <iostream>

CIniciarSesion::CIniciarSesion() {}

void CIniciarSesion::ingresarNick(string nick) {
    this->nickname = nick;
}

bool CIniciarSesion::verificarPas(string pass) {
    return ManejadorUsuario::getInstancia()->verificarCredenciales(nickname, pass);
}

void CIniciarSesion::iniciarSesion() {
    Usuario* u = ManejadorUsuario::getInstancia()->buscarUsuario(nickname);
    if (u) {
        Sesion::getInstancia()->setUsuario(u);
    }
}



CIniciarSesion::~CIniciarSesion() {}