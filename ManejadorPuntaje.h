#ifndef MANEJADORPUNTAJE_H
#define MANEJADORPUNTAJE_H

#include "Puntaje.h"
#include "Pelicula.h"
#include "Usuario.h"
#include <list>
#include <string>

using namespace std;

class ManejadorPuntaje {
private:
    static ManejadorPuntaje* instancia;
    list<Puntaje*> puntajes;
    ManejadorPuntaje();

public:
    static ManejadorPuntaje* getInstancia();
    void agregarPuntaje(Puntaje* puntaje);
    list<Puntaje*>& getPuntajes();
    list<Puntaje*> getPuntajesDePelicula(Pelicula* pelicula);
    list<Puntaje*> getPuntajesDeUsuario(Usuario* usuario);
    bool eliminarPuntajesDePelicula(Pelicula* pelicula);
    bool eliminarPuntajesDeUsuario(Usuario* usuario);
    Puntaje* buscarPuntaje(Usuario* usuario, Pelicula* pelicula);
    float calcularPromedioPelicula(Pelicula* pelicula);
    int contarPuntuacionesPelicula(Pelicula* pelicula);
    ~ManejadorPuntaje();
};

#endif // MANEJADORPUNTAJE_H 