#include "CEliminarPelicula.h"
#include "ManejadorPelicula.h"
#include "ManejadorFuncion.h"
#include "ManejadorComentario.h"
#include "ManejadorPuntaje.h"
#include "Funcion.h"
#include "Pelicula.h"
#include "Reserva.h"
#include "Comentario.h"
#include "Puntaje.h"
#include "ManejadorCine.h"
#include "ManejadorUsuario.h"
#include <algorithm>
#include <stdexcept>

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
        throw invalid_argument("No existe una película con el título: " + titulo);
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
    
    // Eliminar comentarios y puntajes asociados
    eliminarComentariosYPuntajes(pelicula);
    
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

void CEliminarPelicula::eliminarComentariosYPuntajes(Pelicula* pelicula) {
    ManejadorComentario* manejadorComentario = ManejadorComentario::getInstancia();
    map<int, Comentario*>& todosComentarios = manejadorComentario->getComentarios();
    
    // 1. Recopilar TODOS los comentarios a eliminar (principales y respuestas)
    list<int> idsAEliminar;
    
    for (auto& pair : todosComentarios) {
        Comentario* comentario = pair.second;
        if (comentario->getPelicula() == pelicula) {
            // Recopilar IDs de este comentario y todas sus respuestas recursivamente
            recopilarIdsComentarios(comentario, idsAEliminar);
        }
    }
    
    // 2. Eliminar todos los comentarios por ID (evita modificar durante iteración)
    for (int id : idsAEliminar) {
        auto it = todosComentarios.find(id);
        if (it != todosComentarios.end()) {
            delete it->second;  // Liberar memoria
            todosComentarios.erase(it);  // Eliminar del map
        }
    }
    
    // 3. Eliminar puntajes asociados a la película
    eliminarPuntajesDePelicula(pelicula);
}

void CEliminarPelicula::recopilarIdsComentarios(Comentario* comentario, list<int>& idsAEliminar) {
    if (comentario == nullptr) return;
    
    // Agregar el ID de este comentario
    idsAEliminar.push_back(comentario->getId());
    
    // Recopilar IDs de todas las respuestas recursivamente
    list<Comentario*> respuestas = comentario->getRespuestas();
    for (Comentario* respuesta : respuestas) {
        recopilarIdsComentarios(respuesta, idsAEliminar);
    }
}

void CEliminarPelicula::eliminarPuntajesDePelicula(Pelicula* pelicula) {
    ManejadorPuntaje* manejadorPuntaje = ManejadorPuntaje::getInstancia();
    
    // Eliminar todos los puntajes asociados a esta película
    bool puntajesEliminados = manejadorPuntaje->eliminarPuntajesDePelicula(pelicula);
    
    if (puntajesEliminados) {
        // Recalcular promedio de la película (debe ser 0 ya que no hay puntajes)
        pelicula->setPuntajeProm(0.0f);
    }
}

CEliminarPelicula::~CEliminarPelicula() {
    // No eliminar los manejadores ya que son singletons
}