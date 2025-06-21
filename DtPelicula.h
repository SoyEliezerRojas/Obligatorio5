#ifndef DTPELICULA_H
#define DTPELICULA_H
#include <iostream>
#include <string>
using namespace std;

class DtPelicula {
private:
    string titulo;
    string sinopsis;
    string poster;
    float puntajePromedio;
public:
    DtPelicula();
    DtPelicula(string, string, string, float);
    DtPelicula(string titulo, string poster);
    string getTitulo();
    string getSinopsis();
    string getPoster();
    float getPuntajePromedio();
    ~DtPelicula();
    friend ostream& operator << (ostream&, const DtPelicula&);
};
#endif