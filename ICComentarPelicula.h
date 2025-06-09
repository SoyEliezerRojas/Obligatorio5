#ifndef ICCOMENTARPELICULA_H
#define ICCOMENTARPELICULA_H

#include <string>
using namespace std;

class ICComentarPelicula {
public:
    virtual bool hayUsuarioLogueado() = 0;
    virtual void listarPeliculas() = 0;
    virtual void selectPeli(string titulo) = 0;
    virtual void comentar(string texto) = 0;
    virtual void responder(int id, string texto) = 0;
    virtual ~ICComentarPelicula() {}
};

#endif // ICCOMENTARPELICULA_H
