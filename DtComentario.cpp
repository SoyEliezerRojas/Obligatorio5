#include "DtComentario.h"
#include <string>
using namespace std;

DtComentario::DtComentario() {}

DtComentario::DtComentario(int id, string texto, string nombreUsuario) {
    this->id = id;
    this->texto = texto;
    this->nombreUsuario = nombreUsuario;
}

int DtComentario::getId() {
    return this->id;
}

string DtComentario::getTexto() {
    return this->texto;
}

string DtComentario::getNombreUsuario() {
    return this->nombreUsuario;
}

list<DtComentario> DtComentario::getRespuestas() {
    return this->respuestas;
}

void DtComentario::agregarRespuesta(DtComentario respuesta) {
    this->respuestas.push_back(respuesta);
}

DtComentario::~DtComentario() {
    // No need to delete anything as we don't have pointers
}