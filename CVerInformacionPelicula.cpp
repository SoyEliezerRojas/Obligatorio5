#include "CVerInformacionPelicula.h"
#include "Funcion.h"
#include "DtHorario.h"
#include "DtFecha.h"

CVerInformacionPelicula::CVerInformacionPelicula() {
    this->manejadorPelicula = ManejadorPelicula::getInstancia();
    this->manejadorCine = ManejadorCine::getInstancia();
}

list<DtPelicula> CVerInformacionPelicula::listarPeliculas() {
    return manejadorPelicula->listarPeliculas();
}

DtPelicula CVerInformacionPelicula::obtenerInformacionPelicula(string titulo) {
    Pelicula* pelicula = manejadorPelicula->buscarPelicula(titulo);
    if (pelicula == nullptr) {
        return DtPelicula(); // Retorna objeto vacío en lugar de cout
    }
    return pelicula->getDtPelicula();
}

list<DtCine> CVerInformacionPelicula::obtenerCinesPelicula(string titulo) {
    Pelicula* pelicula = manejadorPelicula->buscarPelicula(titulo);
    if (pelicula == nullptr) {
        return list<DtCine>(); // Retorna lista vacía
    }
    
    list<Cine*> cines = pelicula->getCines();
    list<DtCine> dtCines;
    
        for (Cine* cine : cines) {
        DtCine dtCine(cine->getIdCine(), cine->getDirecCine());
        dtCines.push_back(dtCine);
    }
    
    return dtCines;
}

list<DtFuncion> CVerInformacionPelicula::obtenerFuncionesPeliculaEnCine(string titulo, int idCine) {
    Cine* cine = manejadorCine->buscarCine(idCine);
    if (!cine) {
        return list<DtFuncion>(); // Retorna lista vacía
    }
    
    list<Sala*> salas = cine->getSalas();
    list<DtFuncion> funciones;
    
    for (Sala* sala : salas) {
        list<Funcion*> funcionesSala = sala->getFunciones();
        for (Funcion* funcion : funcionesSala) {
            if (funcion->getPelicula() && funcion->getPelicula()->getTitulo() == titulo) {
                DtFuncion dtFuncion(funcion->getIdFun(), funcion->getDiaFun(), funcion->getHoraFun());
                funciones.push_back(dtFuncion);
            }
        }
    }
    
    return funciones;
}

bool CVerInformacionPelicula::validarOpcionMenu(int opcion, int maxOpciones) {
    return (opcion >= 1 && opcion <= maxOpciones);
}

string CVerInformacionPelicula::obtenerTituloPorIndice(int indice) {
    list<DtPelicula> peliculas = manejadorPelicula->listarPeliculas();
    
    if (indice < 0 || indice >= (int)peliculas.size()) {
        return "";
    }
    
    auto it = peliculas.begin();
    advance(it, indice);
    return it->getTitulo();
}

CVerInformacionPelicula::~CVerInformacionPelicula() {
    // No necesitamos liberar manejadorPelicula ni manejadorCine 
    // porque son singletons manejados por el sistema
}