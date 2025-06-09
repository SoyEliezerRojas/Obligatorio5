#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <list>
#include "Reserva.h"

using namespace std;

class Usuario{
private:
    string nickName;
    string pass;
    string urlFoto;
    list<Reserva*> reservas;
public:
    Usuario();
    Usuario(string,string,string);
    string getNickName();
    void setNickName(string);
    string getPass();
    void setPass(string);
    string getUrlFoto();
    void setUrl(string);
    bool verificarPass(string& pass);
    void agregarReserva(Reserva*);
    list<Reserva*> getReservas();
    ~Usuario();
};

#endif