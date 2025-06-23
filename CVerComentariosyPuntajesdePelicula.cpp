#include "CVerComentariosyPuntajesdePelicula.h"
#include "ManejadorPelicula.h"
#include "ManejadorComentario.h"
#include "ManejadorPuntaje.h"
#include "Usuario.h"
#include <vector>
#include <map>
#include <set>
#include <list>
#include <string>
#include <stdexcept>

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

    // Verificar si la película existe
    if (this->peliculaRecordada == nullptr) {
        throw invalid_argument("No existe una película con el título: " + titulo);
    }

    // Mapear Puntajes y calcular promedio usando ManejadorPuntaje
    ManejadorPuntaje* manejadorPuntaje = ManejadorPuntaje::getInstancia();
    list<Puntaje*> puntajesPelicula = manejadorPuntaje->getPuntajesDePelicula(this->peliculaRecordada);
    set<DtPuntaje*> dtPuntajes;
    for (list<Puntaje*>::iterator it = puntajesPelicula.begin(); it != puntajesPelicula.end(); ++it) {
        dtPuntajes.insert((*it)->getDtPuntaje());
    }
    float promedio = manejadorPuntaje->calcularPromedioPelicula(this->peliculaRecordada);
    int cantPuntuaciones = manejadorPuntaje->contarPuntuacionesPelicula(this->peliculaRecordada);

    // Mapear Comentarios
    ManejadorComentario* mc = ManejadorComentario::getInstancia();
    map<int, Comentario*>& todosLosComentarios = mc->getComentarios();
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