#ifndef PELICULA_H
#define PELICULA_H

#include <iostream>
#include <string>
#include <list>
#include "DtPelicula.h"
#include "Cine.h"

using namespace std;

class Pelicula {
private:
    string titulo;
    string sinopsis;
    float puntajeProm;
    string poster;
    list<Cine*> cines;

public:
    // Constructores
    Pelicula();
    Pelicula(string titulo, string sinopsis, float puntajeProm, string poster);
    
    // Getters y setters
    string getTitulo();
    void setTitulo(string titulo);

    string getSinopsis();
    void setSinopsis(string sinopsis);

    float getPuntajeProm();
    void setPuntajeProm(float puntaje);

    string getPoster();
    void setPoster(string poster);
    
    // Métodos de Cine
    void agregarCine(Cine* cine);
    list<Cine*> getCines();
    
    // Otros métodos
    DtPelicula getDtPelicula();
    
    // Destructor
    ~Pelicula();
};

#endif