#ifndef DTPELIFULL_H
#define DTPELIFULL_H

#include <string>
#include <set>
#include "DtPuntaje.h"
#include "DtComentario.h"

using namespace std;

class DtPeliFull {
private:
    string titulo;
    float puntajePromedio;
    int cantPuntuaciones;
    set<DtPuntaje*> puntajes;
    set<DtComentario*> comentarios;

public:
    DtPeliFull(string titulo, float puntajePromedio, int cantPuntuaciones, set<DtPuntaje*> puntajes, set<DtComentario*> comentarios);
    string getTitulo();
    float getPuntajePromedio();
    int getCantPuntuaciones();
    set<DtPuntaje*> getPuntajes();
    set<DtComentario*> getComentarios();
    ~DtPeliFull();
};

#endif
