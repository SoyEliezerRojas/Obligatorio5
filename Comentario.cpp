#include "Comentario.h"
#include <string>
using namespace std;


Comentario::Comentario(){}
Comentario::Comentario(string com){
    this->comentario = com;
}

string Comentario::getComentario(){
    return this->comentario;
}

void Comentario::setComentario(string com){
    this->comentario = com;
}

Comentario::~Comentario(){}