#ifndef ICALTAPELICULA_H
#define ICALTAPELICULA_H

#include <string>

using namespace std;

class ICAltaPelicula {
public:
    virtual bool altaPelicula(string titulo, string sinopsis, string url) = 0;
    virtual ~ICAltaPelicula() {}
};

#endif
