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
    float PuntajePromedio;
public:
    DtPelicula();
    DtPelicula(string, string, string, float);
    string gettitulo();
    string getsinopsis();
    string getposter();
    float getPuntajePromedio();
    ~DtPelicula();
    friend ostream& operator << (ostream&, const DtPelicula&);
};
#endif