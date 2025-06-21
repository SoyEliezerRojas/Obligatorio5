#ifndef DTCOMENTARIO_H
#define DTCOMENTARIO_H

#include <string>
#include <set>

using namespace std;

class DtComentario {
private:
    string nickname;
    string texto;
    set<DtComentario*> respuestas;

public:
    DtComentario(string nickname, string texto);
    string getNickname();
    string getTexto();
    set<DtComentario*> getRespuestas();
    void agregarRespuesta(DtComentario* respuesta);
    ~DtComentario();
};

#endif