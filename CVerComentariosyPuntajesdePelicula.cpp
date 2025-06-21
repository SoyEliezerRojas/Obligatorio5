#include "CVerComentariosyPuntajesdePelicula.h"
#include "ManejadorPelicula.h"
#include "CComentarPelicula.h"
#include "Usuario.h"
#include <vector>
#include <map>
#include <set>
#include <list>
#include <string>

CVerComentariosyPuntajesdePelicula::CVerComentariosyPuntajesdePelicula() {}

set<DtPelicula*> CVerComentariosyPuntajesdePelicula::listarPeliculas() {
    ManejadorPelicula* mp = ManejadorPelicula::getInstancia();
    vector<Pelicula*>& peliculas = mp->getPeliculas();
    set<DtPelicula*> dtPeliculas;
    for (vector<Pelicula*>::iterator it = peliculas.begin(); it != peliculas.end(); ++it) {
        dtPeliculas.insert(new DtPelicula((*it)->getTitulo(), (*it)->getPoster()));
    }
    return dtPeliculas;
}

DtComentario* convertirComentarioADt(Comentario* c) {
    if (c == nullptr) return nullptr;
    DtComentario* dtc = new DtComentario(c->getAutor()->getNickName(), c->getTexto());
    list<Comentario*> respuestas = c->getRespuestas();
    for (list<Comentario*>::iterator it = respuestas.begin(); it != respuestas.end(); ++it) {
        dtc->agregarRespuesta(convertirComentarioADt(*it));
    }
    return dtc;
}

DtPeliFull* CVerComentariosyPuntajesdePelicula::selectPeli(string titulo) {
    ManejadorPelicula* mp = ManejadorPelicula::getInstancia();
    this->peliculaRecordada = mp->obtenerPelicula(titulo);

    // Mapear Puntajes y calcular promedio
    list<Puntaje*>& todosLosPuntajes = mp->getPuntajes();
    set<DtPuntaje*> dtPuntajes;
    float sumaPuntajes = 0;
    int cantPuntuaciones = 0;
    for (list<Puntaje*>::iterator it = todosLosPuntajes.begin(); it != todosLosPuntajes.end(); ++it) {
        if ((*it)->getPelicula()->getTitulo() == titulo) {
            dtPuntajes.insert((*it)->getDtPuntaje());
            sumaPuntajes += (*it)->getPuntaje();
            cantPuntuaciones++;
        }
    }
    float promedio = (cantPuntuaciones > 0) ? (sumaPuntajes / cantPuntuaciones) : 0;

    // Mapear Comentarios
    CComentarPelicula* ccp = CComentarPelicula::getInstancia();
    map<int, Comentario*>& todosLosComentarios = ccp->getComentarios();
    list<DtComentario*> dtComentarios;
    for (map<int, Comentario*>::iterator it = todosLosComentarios.begin(); it != todosLosComentarios.end(); ++it) {
        if (it->second->getPelicula()->getTitulo() == titulo && it->second->getComentarioPadre() == nullptr) {
            dtComentarios.push_back(convertirComentarioADt(it->second));
        }
    }
    
    return new DtPeliFull(
        this->peliculaRecordada->getTitulo(),
        promedio,
        cantPuntuaciones,
        dtPuntajes,
        dtComentarios
    );
}

CVerComentariosyPuntajesdePelicula::~CVerComentariosyPuntajesdePelicula() {} 