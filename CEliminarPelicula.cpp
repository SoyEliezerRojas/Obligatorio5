#include "CEliminarPelicula.h"
#include "ManejadorPelicula.h"
#include "ManejadorFuncion.h"
#include "Funcion.h"
#include "Pelicula.h"
#include "Reserva.h"
#include "ManejadorCine.h"
#include "ManejadorUsuario.h"
#include <algorithm>

CEliminarPelicula::CEliminarPelicula() {
    manejadorPelicula = ManejadorPelicula::getInstancia();
    manejadorFuncion = ManejadorFuncion::getInstancia();
    sesion = Sesion::getInstancia();
}

list<DtPelicula> CEliminarPelicula::listarPeliculas() {
    list<DtPelicula> listaPeliculas;
    // Obtener todas las películas del manejador
    vector<Pelicula*>& peliculas = manejadorPelicula->getPeliculas();
    
    // Convertir a DtPelicula
    for (Pelicula* pelicula : peliculas) {
        if (pelicula != nullptr) {
            listaPeliculas.push_back(pelicula->getDtPelicula());
        }
    }
    
    return listaPeliculas;
}

bool CEliminarPelicula::hayUsuarioLogueado() {
    Usuario* usuario = sesion->getUsuario();
    return (usuario != nullptr);
}

DtPelicula CEliminarPelicula::obtenerInformacionPelicula(string titulo) {
    Pelicula* pelicula = manejadorPelicula->buscarPelicula(titulo);
    
    if (pelicula == nullptr) {
        return DtPelicula(); // Retorna objeto vacío si no existe
    }
    
    return pelicula->getDtPelicula();
}

bool CEliminarPelicula::confirmarEliminacion(string titulo) {
    // Verificar que hay un usuario logueado
    if (!hayUsuarioLogueado()) {
        return false;
    }
    
    // Buscar la película por título
    Pelicula* pelicula = manejadorPelicula->buscarPelicula(titulo);
    
    if (pelicula == nullptr) {
        return false;
    }
    
    // Eliminar funciones asociadas (si las hay)
    eliminarFuncionesAsociadas(titulo);
    
    // Eliminar la película del vector
    vector<Pelicula*>& peliculas = manejadorPelicula->getPeliculas();
    auto it = find(peliculas.begin(), peliculas.end(), pelicula);
    
    if (it != peliculas.end()) {
        peliculas.erase(it);
        delete pelicula;
        return true;
    }
    
    return false;
}

bool CEliminarPelicula::eliminarPelicula(string titulo) {
    return confirmarEliminacion(titulo);
}

void CEliminarPelicula::eliminarFuncionesAsociadas(string tituloPelicula) {
    Pelicula* pelicula = manejadorPelicula->buscarPelicula(tituloPelicula);
    if (!pelicula) return;
    
    ManejadorCine* manejadorCine = ManejadorCine::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    ManejadorFuncion* manejadorFuncion = ManejadorFuncion::getInstancia();

    // 1. Recopilar punteros a funciones a eliminar
    list<Funcion*> funcionesAEliminar;
    list<Funcion*> funciones = manejadorFuncion->getFunciones();
    for (Funcion* funcion : funciones) {
        if (funcion->getPelicula() == pelicula) {
            funcionesAEliminar.push_back(funcion);
        }
    }

    // 2. Eliminar funciones de las salas
    list<Cine*> cines = manejadorCine->getCines();
    for (Cine* cine : cines) {
        list<Sala*> salas = cine->getSalas();
        for (Sala* sala : salas) {
            for (Funcion* funcion : funcionesAEliminar) {
                sala->eliminarFuncion(funcion);
            }
        }
    }

    // 3. Eliminar reservas de usuarios asociadas a esas funciones
    list<Usuario*> usuarios = manejadorUsuario->getUsuarios();
    for (Usuario* usuario : usuarios) {
        for (Funcion* funcion : funcionesAEliminar) {
            list<Reserva*> reservasFuncion = funcion->getReservas();
            for (Reserva* reserva : reservasFuncion) {
                usuario->eliminarReserva(reserva);
            }
        }
    }

    // 4. Eliminar funciones del manejador y sus reservas
    for (Funcion* funcion : funcionesAEliminar) {
        list<Reserva*> reservas = funcion->getReservas();
        for (Reserva* reserva : reservas) {
            delete reserva;
        }
        delete funcion;
        // Si tienes un método para quitar del manejador, agrégalo aquí
    }
}

CEliminarPelicula::~CEliminarPelicula() {
    // No eliminar los manejadores ya que son singletons
}