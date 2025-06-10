#ifndef ICCOMENTARPELICULA_H
#define ICCOMENTARPELICULA_H

#include <string>
#include <list>
#include "DtPelicula.h"

class ICComentarPelicula {
public:
    virtual bool hayUsuarioLogueado() = 0;
    virtual void listarPeliculas() = 0;
    virtual void selectPeli(string titulo) = 0;
    virtual void comentar(string texto) = 0;
    virtual void responder(int idComentario, string texto) = 0;
    virtual ~ICComentarPelicula() {}
};

#endif
