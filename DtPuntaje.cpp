#include "DtPuntaje.h"

DtPuntaje::DtPuntaje(float valor, string nickUsuario, string tituloPelicula) {
    this->valor = valor;
    this->nickUsuario = nickUsuario;
    this->tituloPelicula = tituloPelicula;
}

float DtPuntaje::getValor() {
    return this->valor;
}

string DtPuntaje::getNickUsuario() {
    return this->nickUsuario;
}

string DtPuntaje::getTituloPelicula() {
    return this->tituloPelicula;
}

DtPuntaje::~DtPuntaje() {}