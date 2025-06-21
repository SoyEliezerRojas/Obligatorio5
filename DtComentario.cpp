#include "DtComentario.h"
#include <string>
#include <set>
using namespace std;

DtComentario::DtComentario(string nickname, string texto) {
    this->nickname = nickname;
    this->texto = texto;
}

string DtComentario::getNickname() {
    return this->nickname;
}

string DtComentario::getTexto() {
    return this->texto;
}

set<DtComentario*> DtComentario::getRespuestas() {
    return this->respuestas;
}

void DtComentario::agregarRespuesta(DtComentario* respuesta) {
    this->respuestas.insert(respuesta);
}

DtComentario::~DtComentario() {
    for (set<DtComentario*>::iterator it = this->respuestas.begin(); it != this->respuestas.end(); ++it) {
        delete *it;
    }
    this->respuestas.clear();
}