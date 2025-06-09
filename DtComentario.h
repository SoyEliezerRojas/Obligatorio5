#ifndef DTCOMENTARIO_H
#define DTCOMENTARIO_H
#include <string>
#include <list>

using namespace std;

class DtComentario {
private:
    int id;
    string texto;
    string nombreUsuario;
    list<DtComentario> respuestas;

public:
    DtComentario();
    DtComentario(int id, string texto, string nombreUsuario);
    
    int getId();
    string getTexto();
    string getNombreUsuario();
    list<DtComentario> getRespuestas();
    
    void agregarRespuesta(DtComentario respuesta);
    
    ~DtComentario();
};

#endif