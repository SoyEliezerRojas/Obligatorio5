#include "CAltaFuncion.h"
#include "DtHorario.h"
#include "Sesion.h"
#include "ManejadorPelicula.h"
#include "ManejadorCine.h"
#include "ManejadorFuncion.h"
#include "Pelicula.h"
#include "Cine.h"
#include "Sala.h"
#include "Funcion.h"

CAltaFuncion::CAltaFuncion() {
    this->peliculaSeleccionada = NULL;
    this->cineSeleccionado = NULL;
    this->salaSeleccionada = NULL;
}

list<DtPelicula> CAltaFuncion::listarPeliculas() {
    list<DtPelicula> dtPeliculas;
    vector<Pelicula*> peliculas = ManejadorPelicula::getInstancia()->getPeliculas();
    for (vector<Pelicula*>::iterator it = peliculas.begin(); it != peliculas.end(); ++it) {
        DtPelicula dtPeli((*it)->getTitulo(), (*it)->getSinopsis(), (*it)->getPoster(), (*it)->getPuntajeProm());
        dtPeliculas.push_back(dtPeli);
    }
    return dtPeliculas;
}

void CAltaFuncion::selectPeli(string titulo) {
    this->tituloPelicula = titulo;
}

list<DtCine> CAltaFuncion::listarCines() {
    list<DtCine> dtCines;
    list<Cine*> cines = ManejadorCine::getInstancia()->getCines();
    for (list<Cine*>::iterator it = cines.begin(); it != cines.end(); ++it) {
        DtCine dtCine((*it)->getIdCine(), (*it)->getDirecCine());
        dtCines.push_back(dtCine);
    }
    return dtCines;
}

void CAltaFuncion::selectCine(string idCine) {
    this->idCine = idCine;
}

list<DtSala> CAltaFuncion::listarSalas() {
    list<DtSala> dtSalas;
    Cine* cine = ManejadorCine::getInstancia()->buscarCine(stoi(this->idCine));
    if (cine != NULL) {
        list<Sala*> salas = cine->getSalas();
        for (list<Sala*>::iterator it = salas.begin(); it != salas.end(); ++it) {
            DtSala dtSala((*it)->getId(), (*it)->getCapacidad());
            dtSalas.push_back(dtSala);
        }
    }
    return dtSalas;
}

void CAltaFuncion::selectSala(int idSala) {
    this->idSala = idSala;
}

void CAltaFuncion::altaFuncion(string horaInicio, DtFecha fecha) {
    ManejadorPelicula* mP = ManejadorPelicula::getInstancia();
    ManejadorCine* mC = ManejadorCine::getInstancia();
    ManejadorFuncion* mF = ManejadorFuncion::getInstancia();

    Pelicula* pelicula = mP->buscarPelicula(tituloPelicula);
    Cine* cine = mC->buscarCine(stoi(idCine));
    Sala* sala = NULL;

    // Buscar la sala en el cine
    list<Sala*> salas = cine->getSalas();
    for (list<Sala*>::iterator it = salas.begin(); it != salas.end(); ++it) {
        if ((*it)->getId() == idSala) {
            sala = *it;
            break;
        }
    }

    if (pelicula != NULL && cine != NULL && sala != NULL) {
        // Crear la función
        int idFuncion = mF->getNextId();
        DtHorario horario(horaInicio, ""); // La hora de fin se calcula en la función
        Funcion* funcion = new Funcion(idFuncion, fecha, horario);
        funcion->setPelicula(pelicula);
        funcion->setPrecio(200); // Precio por defecto

        // Agregar la función a la sala
        sala->agregarFuncion(funcion);
        
        // Agregar la función al manejador de funciones
        mF->agregarFuncion(funcion);

        // Agregar el cine a la lista de cines de la película si no está ya
        bool cineExiste = false;
        list<Cine*> cinesPelicula = pelicula->getCines();
        for (list<Cine*>::iterator it = cinesPelicula.begin(); it != cinesPelicula.end(); ++it) {
            if ((*it)->getIdCine() == cine->getIdCine()) {
                cineExiste = true;
                break;
            }
        }
        if (!cineExiste) {
            pelicula->agregarCine(cine);
        }
    }
}

bool CAltaFuncion::hayUsuarioLogueado() {
    return Sesion::getInstancia()->getUsuario() != NULL;
}

CAltaFuncion::~CAltaFuncion() {
    // No necesitamos eliminar los punteros ya que son manejados por sus respectivos manejadores
    this->peliculaSeleccionada = NULL;
    this->cineSeleccionado = NULL;
    this->salaSeleccionada = NULL;
}
