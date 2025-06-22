#ifndef MANEJADORCOMENTARIO_H
#define MANEJADORCOMENTARIO_H

#include "Comentario.h"
#include <map>
#include <string>

using namespace std;

class ManejadorComentario {
private:
    static ManejadorComentario* instancia;
    map<int, Comentario*> comentarios;
    int nextCommentId;
    ManejadorComentario();

public:
    static ManejadorComentario* getInstancia();
    void agregarComentario(Comentario* comentario);
    map<int, Comentario*>& getComentarios();
    Comentario* obtenerComentario(int id);
    int getNextCommentId();
    void incrementarNextCommentId();
    ~ManejadorComentario();
};

#endif // MANEJADORCOMENTARIO_H 