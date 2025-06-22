#include "ManejadorComentario.h"

using namespace std;

ManejadorComentario* ManejadorComentario::instancia = nullptr;

ManejadorComentario* ManejadorComentario::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ManejadorComentario();
    }
    return instancia;
}

ManejadorComentario::ManejadorComentario() {
    this->nextCommentId = 1;
}

void ManejadorComentario::agregarComentario(Comentario* comentario) {
    if (comentario != nullptr) {
        comentario->setId(this->nextCommentId);
        this->comentarios[this->nextCommentId] = comentario;
        this->nextCommentId++;
    }
}

map<int, Comentario*>& ManejadorComentario::getComentarios() {
    return this->comentarios;
}

Comentario* ManejadorComentario::obtenerComentario(int id) {
    if (this->comentarios.count(id) > 0) {
        return this->comentarios[id];
    }
    return nullptr;
}

int ManejadorComentario::getNextCommentId() {
    return this->nextCommentId;
}

void ManejadorComentario::incrementarNextCommentId() {
    this->nextCommentId++;
}

ManejadorComentario::~ManejadorComentario() {
    // Liberar todos los comentarios
    for (map<int, Comentario*>::iterator it = comentarios.begin(); it != comentarios.end(); ++it) {
        delete it->second;
    }
    comentarios.clear();
}