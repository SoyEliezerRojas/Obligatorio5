#include "CVerInformacionPelicula.h"
#include "Funcion.h"
#include "DtHorario.h"
#include "DtFecha.h"
#include "Reloj.h"
#include <string>
#include <list>
#include <algorithm>
#include <stdexcept>

using namespace std;

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
        throw invalid_argument("No existe una película con el título: " + titulo);
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

// Función auxiliar para comparar si una función es posterior a la fecha y hora actual
bool CVerInformacionPelicula::esFuncionPosterior(DtFuncion& funcion) {
    Reloj* reloj = Reloj::getInstancia();
    DtFecha fechaActual = reloj->getFechaActual();
    string horaActual = reloj->getHoraActual();
    
    DtFecha fechaFuncion = funcion.getDiaFun();
    DtHorario horarioFuncion = funcion.getHoraFun();
    
    // Si la fecha de la función es posterior a la fecha actual
    if (fechaActual < fechaFuncion) {
        return true;
    }
    
    // Si es el mismo día, comparar horarios
    if (fechaActual.getDia() == fechaFuncion.getDia() && 
        fechaActual.getMes() == fechaFuncion.getMes() && 
        fechaActual.getAnio() == fechaFuncion.getAnio()) {
        
        // Comparar hora de inicio de la función con la hora actual
        string horaInicioFuncion = horarioFuncion.getHoraIni();
        return compararHoras(horaActual, horaInicioFuncion);
    }
    
    return false;
}

// Función auxiliar para comparar horas en formato "hh:mm"
bool CVerInformacionPelicula::compararHoras(const string& horaActual, const string& horaFuncion) {
    // Extraer horas y minutos
    int horaActualH = stoi(horaActual.substr(0, 2));
    int horaActualM = stoi(horaActual.substr(3, 2));
    int horaFuncionH = stoi(horaFuncion.substr(0, 2));
    int horaFuncionM = stoi(horaFuncion.substr(3, 2));
    
    // Convertir a minutos totales para facilitar la comparación
    int minutosActual = horaActualH * 60 + horaActualM;
    int minutosFuncion = horaFuncionH * 60 + horaFuncionM;
    
    return minutosFuncion > minutosActual;
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
                
                // Solo agregar funciones posteriores a la fecha y hora actual
                if (esFuncionPosterior(dtFuncion)) {
                    funciones.push_back(dtFuncion);
                }
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