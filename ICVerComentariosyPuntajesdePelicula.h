#ifndef ICVERCOMENTARIOSYPUNTAJESDEPELICULA_H
#define ICVERCOMENTARIOSYPUNTAJESDEPELICULA_H

#include <string>
#include <set>
#include "DtPelicula.h"
#include "DtPeliFull.h"

using namespace std;

class ICVerComentariosyPuntajesdePelicula {
public:
    virtual set<DtPelicula*> listarPeliculas() = 0;
    virtual DtPeliFull* selectPeli(string titulo) = 0;
};

#endif
