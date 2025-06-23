#include "ManejadorPuntaje.h"

ManejadorPuntaje* ManejadorPuntaje::instancia = nullptr;

ManejadorPuntaje::ManejadorPuntaje() {}

ManejadorPuntaje* ManejadorPuntaje::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ManejadorPuntaje();
    }
    return instancia;
}

void ManejadorPuntaje::agregarPuntaje(Puntaje* puntaje) {
    if (puntaje != nullptr) {
        // Verificar si ya existe un puntaje de este usuario para esta película
        Puntaje* puntajeExistente = buscarPuntaje(puntaje->getUsuario(), puntaje->getPelicula());
        if (puntajeExistente != nullptr) {
            // Actualizar puntaje existente
            puntajes.remove(puntajeExistente);
            delete puntajeExistente;
        }
        puntajes.push_back(puntaje);
    }
}

list<Puntaje*>& ManejadorPuntaje::getPuntajes() {
    return puntajes;
}

list<Puntaje*> ManejadorPuntaje::getPuntajesDePelicula(Pelicula* pelicula) {
    list<Puntaje*> puntajesPelicula;
    for (list<Puntaje*>::iterator it = puntajes.begin(); it != puntajes.end(); ++it) {
        if ((*it)->getPelicula() == pelicula) {
            puntajesPelicula.push_back(*it);
        }
    }
    return puntajesPelicula;
}

list<Puntaje*> ManejadorPuntaje::getPuntajesDeUsuario(Usuario* usuario) {
    list<Puntaje*> puntajesUsuario;
    for (list<Puntaje*>::iterator it = puntajes.begin(); it != puntajes.end(); ++it) {
        if ((*it)->getUsuario() == usuario) {
            puntajesUsuario.push_back(*it);
        }
    }
    return puntajesUsuario;
}

bool ManejadorPuntaje::eliminarPuntajesDePelicula(Pelicula* pelicula) {
    list<Puntaje*> puntajesAEliminar;
    
    // Recopilar puntajes a eliminar
    for (list<Puntaje*>::iterator it = puntajes.begin(); it != puntajes.end(); ++it) {
        if ((*it)->getPelicula() == pelicula) {
            puntajesAEliminar.push_back(*it);
        }
    }
    
    // Eliminar puntajes
    for (Puntaje* puntaje : puntajesAEliminar) {
        puntajes.remove(puntaje);
        delete puntaje;
    }
    
    return !puntajesAEliminar.empty();
}

bool ManejadorPuntaje::eliminarPuntajesDeUsuario(Usuario* usuario) {
    list<Puntaje*> puntajesAEliminar;
    
    // Recopilar puntajes a eliminar
    for (list<Puntaje*>::iterator it = puntajes.begin(); it != puntajes.end(); ++it) {
        if ((*it)->getUsuario() == usuario) {
            puntajesAEliminar.push_back(*it);
        }
    }
    
    // Eliminar puntajes
    for (Puntaje* puntaje : puntajesAEliminar) {
        puntajes.remove(puntaje);
        delete puntaje;
    }
    
    return !puntajesAEliminar.empty();
}

Puntaje* ManejadorPuntaje::buscarPuntaje(Usuario* usuario, Pelicula* pelicula) {
    for (list<Puntaje*>::iterator it = puntajes.begin(); it != puntajes.end(); ++it) {
        if ((*it)->getUsuario() == usuario && (*it)->getPelicula() == pelicula) {
            return *it;
        }
    }
    return nullptr;
}

float ManejadorPuntaje::calcularPromedioPelicula(Pelicula* pelicula) {
    list<Puntaje*> puntajesPelicula = getPuntajesDePelicula(pelicula);
    
    if (puntajesPelicula.empty()) {
        return 0.0f;
    }
    
    float suma = 0.0f;
    for (Puntaje* puntaje : puntajesPelicula) {
        suma += puntaje->getPuntaje();
    }
    
    return suma / puntajesPelicula.size();
}

int ManejadorPuntaje::contarPuntuacionesPelicula(Pelicula* pelicula) {
    return getPuntajesDePelicula(pelicula).size();
}

ManejadorPuntaje::~ManejadorPuntaje() {
    for (Puntaje* puntaje : puntajes) {
        delete puntaje;
    }
    puntajes.clear();
} 