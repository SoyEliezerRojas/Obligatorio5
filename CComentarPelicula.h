#ifndef CCOMENTARPELICULA_H
#define CCOMENTARPELICULA_H

#include "ICComentarPelicula.h"
#include "ManejadorPelicula.h"
#include "ManejadorUsuario.h"
#include "Pelicula.h"
#include "Usuario.h"
#include "Comentario.h"
#include <string>
#include <map>

class CComentarPelicula : public ICComentarPelicula {
private:
    ManejadorPelicula* manejadorPelicula;
    ManejadorUsuario* manejadorUsuario;
    Pelicula* peliculaSeleccionada;
    map<int, Comentario*> comentarios;
    int nextCommentId;

public:
    CComentarPelicula();
    bool hayUsuarioLogueado();
    void listarPeliculas();
    void selectPeli(string titulo);
    void comentar(string texto);
    void responder(int id, string texto);
    Comentario* obtenerComentario(int id);
    ~CComentarPelicula();
};

#endif // CCOMENTARPELICULA_H