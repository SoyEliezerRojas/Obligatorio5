#include "CIniciarSesion.h"

CIniciarSesion* CIniciarSesion::instancia = nullptr;

CIniciarSesion::CIniciarSesion() {}

CIniciarSesion* CIniciarSesion::getInstancia() {
    if (instancia == nullptr) {
        instancia = new CIniciarSesion();
    }
    return instancia;
}

bool CIniciarSesion::iniciarSesion(string& nickname, string& password) {
    // En un sistema real, aquí se buscaría el usuario en una base de datos
    // Por ahora, crearemos un usuario de prueba "nick" como se muestra en el diagrama
    if (nickname == "nick") {
        string urlFotoDefault = "default.jpg"; // URL por defecto para el usuario
        Usuario* usuario = new Usuario(nickname, password, urlFotoDefault);
        if (usuario->verificarPass(password)) {
            Sesion::getInstancia()->setUsuario(usuario);
            return true;
        }
        delete usuario;
    }
    return false;
}

CIniciarSesion::~CIniciarSesion() {
    if (instancia != nullptr) {
        delete instancia;
        instancia = nullptr;
    }
}
