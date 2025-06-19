#ifndef CALTAPELICULA_H
#define CALTAPELICULA_H

#include "ICAltaPelicula.h"
#include <string>

using namespace std;

class CAltaPelicula : public ICAltaPelicula {
public:
    CAltaPelicula();
    bool altaPelicula(string titulo, string sinopsis, string url);
    bool hayUsuarioLogueado();
    bool verificarExistenciaPelicula(string titulo);
    ~CAltaPelicula();
};

#endif 