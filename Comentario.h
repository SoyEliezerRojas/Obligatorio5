#ifndef COMENTARIO_H
#define COMENTARIO_H
#include <string>
#include <list>
#include "Usuario.h"
#include "Pelicula.h"

using namespace std;

class Comentario {
private:
    int id;
    string texto;
    Usuario* autor;
    Pelicula* pelicula;
    list<Comentario*> respuestas;
    Comentario* comentarioPadre;

public:
    Comentario();
    Comentario(string texto, Usuario* autor, Pelicula* pelicula);
    int getId();
    void setId(int id);
    string getTexto();
    void setTexto(string texto);
    Usuario* getAutor();
    void setAutor(Usuario* autor);
    Pelicula* getPelicula();
    void setPelicula(Pelicula* pelicula);
    list<Comentario*> getRespuestas();
    void agregarRespuesta(Comentario* respuesta);
    Comentario* getComentarioPadre();
    void setComentarioPadre(Comentario* padre);
    ~Comentario();
};

#endif