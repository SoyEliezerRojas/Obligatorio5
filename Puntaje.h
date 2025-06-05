#ifndef PUNTAJE_H
#define PUNTAJE_H
#include <iostream>
class Puntaje{
private:
    int puntaje;
public:
    Puntaje();
    Puntaje(int);
    int getPuntaje();
    void setPuntaje(int pj);
    ~Puntaje();
};



#endif