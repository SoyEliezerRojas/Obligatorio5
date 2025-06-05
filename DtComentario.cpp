#include "DtComentario.h"
#include <string>
using namespace std;


DtComentario::DtComentario(){}
DtComentario::DtComentario(string com){
    this->comentario = com;
}

string DtComentario::getComentario(){
    return this->comentario;
}

DtComentario::~DtComentario(){}