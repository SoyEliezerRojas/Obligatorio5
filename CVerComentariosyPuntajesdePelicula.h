#ifndef CVERCOMENTARIOSYPUNTAJESDEPELICULA_H
#define CVERCOMENTARIOSYPUNTAJESDEPELICULA_H

#include "ICVerComentariosyPuntajesdePelicula.h"
#include "ManejadorPelicula.h"
#include "Pelicula.h"
#include <string>

using namespace std;

class CVerComentariosyPuntajesdePelicula : public ICVerComentariosyPuntajesdePelicula {
private:
    Pelicula* peliculaRecordada;

public:
    CVerComentariosyPuntajesdePelicula();
    set<DtPelicula*> listarPeliculas();
    DtPeliFull* selectPeli(string titulo);
    ~CVerComentariosyPuntajesdePelicula();
};

#endif
