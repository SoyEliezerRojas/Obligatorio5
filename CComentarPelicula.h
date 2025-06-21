#ifndef CCOMENTARPELICULA_H
#define CCOMENTARPELICULA_H

#include "ICComentarPelicula.h"
#include "ManejadorPelicula.h"
#include "ManejadorUsuario.h"
#include "Pelicula.h"
#include "Usuario.h"
#include "Comentario.h"
#include "DtComentario.h"
#include <string>
#include <map>
#include <list>

using namespace std;

class CComentarPelicula : public ICComentarPelicula {
private:
    static CComentarPelicula* instancia;
    CComentarPelicula();
    ManejadorPelicula* manejadorPelicula;
    ManejadorUsuario* manejadorUsuario;
    Pelicula* peliculaSeleccionada;
    map<int, Comentario*> comentarios;
    int nextCommentId;
    DtComentario* convertirComentarioADt(Comentario* comentario);

public:
    static CComentarPelicula* getInstancia();
    bool hayUsuarioLogueado();
    list<DtPelicula> listarPeliculas();
    void selectPeli(string titulo);
    void comentar(string texto);
    void responder(int id, string texto);
    Comentario* obtenerComentario(int id);
    map<int, Comentario*>& getComentarios();
    list<DtComentario*> obtenerComentariosPeliculaSeleccionada();
    ~CComentarPelicula();
};

#endif // CCOMENTARPELICULA_H