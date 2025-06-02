#ifndef SALA_H
#define SALA_H
#include <iostream>

class Sala{
private:
    int sala;
    int capacidad;
public:
    Sala();
    Sala(int, int);
    int getSala();
    void setSala(int);

    int getCapacidad();
    void setCapacidad(int);
    ~Sala();
};

#endif



