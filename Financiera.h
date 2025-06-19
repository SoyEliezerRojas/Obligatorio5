#ifndef FINANCIERA_H
#define FINANCIERA_H

#include <string>
using namespace std;

class Financiera {
private:
    string nombre;
    float descuento;

public:
    Financiera();
    Financiera(string nombre, float descuento);
    
    string getNombre();
    void setNombre(string nombre);
    
    float getDescuento();
    void setDescuento(float descuento);
    
    ~Financiera();
};

#endif 