#ifndef DTPELIFULL_H
#define DTPELIFULL_H

#include <string>
#include <set>
#include <list>
#include "DtPuntaje.h"
#include "DtComentario.h"

using namespace std;

class DtPeliFull {
private:
    string titulo;
    float puntajePromedio;
    int cantPuntuaciones;
    set<DtPuntaje*> puntajes;
    list<DtComentario*> comentarios;

public:
    DtPeliFull(string titulo, float puntajePromedio, int cantPuntuaciones, set<DtPuntaje*> puntajes, list<DtComentario*> comentarios);
    string getTitulo();
    float getPuntajePromedio();
    int getCantPuntuaciones();
    set<DtPuntaje*> getPuntajes();
    list<DtComentario*> getComentarios();
    ~DtPeliFull();
};

#endif
