#ifndef COMENTARIO_H
#define COMENTARIO_H
#include <string>

using namespace std;

class Comentario{
private:
    string comentario;
public:
    Comentario();
    Comentario(string);
    string getComentario();
    void setComentario(string);
    ~Comentario();
};

#endif