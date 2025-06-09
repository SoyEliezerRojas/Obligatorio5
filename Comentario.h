#ifndef COMENTARIO_H
#define COMENTARIO_H
#include <string>
#include <list>
#include "Usuario.h"

using namespace std;

// Forward declaration
class Pelicula;

class Comentario {
private:
    int id;
    string texto;
    Usuario* usuario;
    Pelicula* pelicula;
    list<Comentario*> respuestas;

public:
    Comentario();
    Comentario(string texto, Usuario* usuario, Pelicula* pelicula);
    
    int getId();
    string getTexto();
    Usuario* getUsuario();
    Pelicula* getPelicula();
    list<Comentario*> getRespuestas();
    
    void setId(int id);
    void setTexto(string texto);
    void agregarRespuesta(Comentario* respuesta);
    
    ~Comentario();
};

#endif