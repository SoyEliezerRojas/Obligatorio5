#include "DtPeliFull.h"

DtPeliFull::DtPeliFull(string titulo, float puntajePromedio, int cantPuntuaciones, set<DtPuntaje*> puntajes, list<DtComentario*> comentarios) {
    this->titulo = titulo;
    this->puntajePromedio = puntajePromedio;
    this->cantPuntuaciones = cantPuntuaciones;
    this->puntajes = puntajes;
    this->comentarios = comentarios;
}

string DtPeliFull::getTitulo() {
    return this->titulo;
}

float DtPeliFull::getPuntajePromedio() {
    return this->puntajePromedio;
}

int DtPeliFull::getCantPuntuaciones() {
    return this->cantPuntuaciones;
}

set<DtPuntaje*> DtPeliFull::getPuntajes() {
    return this->puntajes;
}

list<DtComentario*> DtPeliFull::getComentarios() {
    return this->comentarios;
}

DtPeliFull::~DtPeliFull() {
    for (set<DtPuntaje*>::iterator it = this->puntajes.begin(); it != this->puntajes.end(); ++it) {
        delete *it;
    }
    this->puntajes.clear();

    for (list<DtComentario*>::iterator it = this->comentarios.begin(); it != this->comentarios.end(); ++it) {
        delete *it;
    }
    this->comentarios.clear();
}
