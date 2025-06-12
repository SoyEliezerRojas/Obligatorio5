#include "CVerReservasDePelicula.h"
#include "ManejadorPelicula.h"
#include "ManejadorFuncion.h"
#include "Sesion.h"

CVerReservasDePelicula* CVerReservasDePelicula::instancia = NULL;

CVerReservasDePelicula* CVerReservasDePelicula::getInstancia() {
    if (instancia == NULL) {
        instancia = new CVerReservasDePelicula();
    }
    return instancia;
}

list<DtPelicula> CVerReservasDePelicula::listarPeliculas() {
    ManejadorPelicula* mP = ManejadorPelicula::getInstancia();
    return mP->listarPeliculas();
}

void CVerReservasDePelicula::selectPelicula(string titulo) {
    this->tituloSeleccionado = titulo;
}

list<DtFuncion> CVerReservasDePelicula::listarFunciones() {
    ManejadorPelicula* mP = ManejadorPelicula::getInstancia();
    Pelicula* pelicula = mP->buscarPelicula(tituloSeleccionado);
    if (pelicula != NULL) {
        list<Cine*> cines = pelicula->getCines();
        list<DtFuncion> funciones;
        for (Cine* cine : cines) {
            list<Sala*> salas = cine->getSalas();
            for (Sala* sala : salas) {
                list<Funcion*> funcionesSala = sala->getFunciones();
                for (Funcion* funcion : funcionesSala) {
                    if (funcion->getTituloPelicula() == tituloSeleccionado) {
                        DtFuncion dtFuncion(
                            funcion->getIdFun(),
                            funcion->getDiaFun(),
                            funcion->getHoraFun()
                        );
                        funciones.push_back(dtFuncion);
                    }
                }
            }
        }
        return funciones;
    }
    return list<DtFuncion>();
}

void CVerReservasDePelicula::selectFuncion(int idFuncion) {
    this->idFuncionSeleccionada = idFuncion;
}

list<DtReserva> CVerReservasDePelicula::listarReservas() {
    ManejadorPelicula* mP = ManejadorPelicula::getInstancia();
    Pelicula* pelicula = mP->buscarPelicula(tituloSeleccionado);
    if (pelicula != NULL) {
        return pelicula->listarReservas();
    }
    return list<DtReserva>();
}

list<DtReserva> CVerReservasDePelicula::listarReservasDePelicula(string titulo) {
    ManejadorPelicula* mP = ManejadorPelicula::getInstancia();
    Pelicula* pelicula = mP->buscarPelicula(titulo);
    if (pelicula != NULL) {
        return pelicula->listarReservas();
    }
    return list<DtReserva>();
}

CVerReservasDePelicula::~CVerReservasDePelicula() {
    if (instancia != NULL) {
        delete instancia;
        instancia = NULL;
    }
}
