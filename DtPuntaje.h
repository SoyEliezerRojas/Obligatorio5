#ifndef DTPUNTAJE_H
#define DTPUNTAJE_H

#include <string>
using namespace std;

class DtPuntaje {
    private:
        float valor;
        string nickUsuario;
        string tituloPelicula;
        
    public:
        DtPuntaje(float valor, string nickUsuario, string tituloPelicula);
        float getValor();
        string getNickUsuario();
        string getTituloPelicula();
        ~DtPuntaje();
};

#endif