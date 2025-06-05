#ifndef DTCOMENTARIO_H
#define DTCOMENTARIO_H
#include <string>

using namespace std;

class DtComentario{
private:
    string comentario;
public:
    DtComentario();
    DtComentario(string);
    string getComentario();
    ~DtComentario();
};

#endif