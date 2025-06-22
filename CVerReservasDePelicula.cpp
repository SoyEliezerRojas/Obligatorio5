#include "CVerReservasDePelicula.h"
#include "ManejadorPelicula.h"
#include "ManejadorFuncion.h"
#include "Pelicula.h"
#include "Funcion.h"
#include "Sesion.h"

CVerReservasDePelicula::CVerReservasDePelicula() {}

list<DtPelicula> CVerReservasDePelicula::listarPeliculas() {
    ManejadorPelicula* mP = ManejadorPelicula::getInstancia();
    vector<Pelicula*>& peliculas = mP->getPeliculas();
    list<DtPelicula> dtPeliculas;
    for (auto const& p : peliculas) {
        dtPeliculas.push_back(p->getDtPelicula());
    }
    return dtPeliculas;
}

list<DtFuncion> CVerReservasDePelicula::obtenerFuncionesDePelicula(string titulo) {
    list<DtFuncion> funcionesDePelicula;
    ManejadorFuncion* mf = ManejadorFuncion::getInstancia();
    list<Funcion*> todasLasFunciones = mf->getFunciones();

    for (list<Funcion*>::iterator it = todasLasFunciones.begin(); it != todasLasFunciones.end(); ++it) {
        if ((*it)->getPelicula() != nullptr && (*it)->getPelicula()->getTitulo() == titulo) {
            DtFuncion dtF((*it)->getIdFun(), (*it)->getDiaFun(), (*it)->getHoraFun());
            funcionesDePelicula.push_back(dtF);
        }
    }
    return funcionesDePelicula;
}

list<DtReserva> CVerReservasDePelicula::obtenerReservasDeFuncion(int idFuncion) {
    ManejadorFuncion* mf = ManejadorFuncion::getInstancia();
    Funcion* funcion = mf->buscarFuncion(idFuncion);

    if (funcion != nullptr) {
        return funcion->listarReservas();
    }

    return list<DtReserva>();
}

CVerReservasDePelicula::~CVerReservasDePelicula() {
    // Destructor simple - no hay recursos especiales que liberar
}