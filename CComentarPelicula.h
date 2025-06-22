#ifndef CCOMENTARPELICULA_H
#define CCOMENTARPELICULA_H

#include "ICComentarPelicula.h"
#include "ManejadorPelicula.h"
#include "ManejadorUsuario.h"
#include "ManejadorComentario.h"
#include "Pelicula.h"
#include "Usuario.h"
#include "Comentario.h"
#include "DtComentario.h"
#include <string>
#include <map>
#include <list>
#include <vector>

using namespace std;

class CComentarPelicula : public ICComentarPelicula {
private:
    ManejadorPelicula* manejadorPelicula;
    ManejadorUsuario* manejadorUsuario;
    ManejadorComentario* manejadorComentario;
    Pelicula* peliculaSeleccionada;
    DtComentario* convertirComentarioADt(Comentario* comentario);

public:
    CComentarPelicula();
    bool hayUsuarioLogueado();
    list<DtPelicula> listarPeliculas();
    void selectPeli(string titulo);
    void comentar(string texto);
    void responder(int id, string texto);
    Comentario* obtenerComentario(int id);
    map<int, Comentario*>& getComentarios();
    list<DtComentario*> obtenerComentariosPeliculaSeleccionada();
    vector<int> obtenerIdsComentariosPeliculaSeleccionada();
    ~CComentarPelicula();
};

#endif // CCOMENTARPELICULA_H