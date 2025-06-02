#ifndef PELICULA_H
#define PELICULA_H
#include<iostream>
#include<string>

using namespace std;

class Pelicula{
private:
    string titulo;
    string sinopsis;
    float puntajeProm;
    string poster;
public:
    Pelicula();
    Pelicula(string,string,float,string);
    string getTitulo();
    void setTit(string);

    string getSinopsis();
    void setSinopsis(string);

    float getPuntajeProm();
    void setPuntajeProm(float);

    string getPoster();
    void setPoster(string);
    ~Pelicula();
};

#endif