#include "CEliminarPelicula.h"
#include "ManejadorPelicula.h"
#include "ManejadorFuncion.h"
#include "Funcion.h"
#include "Pelicula.h"
#include "Reserva.h"
#include <iostream>
#include <algorithm>

CEliminarPelicula::CEliminarPelicula() {
    manejadorPelicula = ManejadorPelicula::getInstancia();
    manejadorFuncion = ManejadorFuncion::getInstancia();
    sesion = Sesion::getInstancia();
}

list<DtPelicula> CEliminarPelicula::listarPeliculas() {
    list<DtPelicula> listaPeliculas;
    // Verificar que hay un usuario logueado
    if (!hayUsuarioLogueado()) {
        cout << "Error: Debe iniciar sesión para eliminar películas." << endl;
        return listaPeliculas;
    }
    // Obtener todas las películas del manejador
    vector<Pelicula*>& peliculas = manejadorPelicula->getPeliculas();
    
    if (peliculas.empty()) {
        cout << "No hay películas registradas en el sistema." << endl;
        return listaPeliculas;
    }
    // Convertir a DtPelicula
    for (Pelicula* pelicula : peliculas) {
        if (pelicula != nullptr) {
            listaPeliculas.push_back(pelicula->getDtPelicula());
        }
    }
    
    return listaPeliculas;
}

bool CEliminarPelicula::eliminarPelicula(string titulo) {
    // Verificar que hay un usuario logueado
    if (!hayUsuarioLogueado()) {
        cout << "Error: Debe iniciar sesión para eliminar películas." << endl;
        return false;
    }
    // Buscar la película por título
    Pelicula* pelicula = manejadorPelicula->buscarPelicula(titulo);
    
    if (pelicula == nullptr) {
        cout << "Error: La película '" << titulo << "' no existe." << endl;
        return false;
    }
    // Mostrar información de la película
    cout << "\n=== PELÍCULA A ELIMINAR ===" << endl;
    cout << "Título: " << pelicula->getTitulo() << endl;
    cout << "Sinopsis: " << pelicula->getSinopsis() << endl;
    cout << "Póster: " << pelicula->getPoster() << endl;
    cout << "============================" << endl;
    
    // Pedir confirmación
    char confirmacion;
    cout << "\n¿Está seguro de que desea eliminar esta película?" << endl;
    cout << "ADVERTENCIA: Se eliminarán todas las funciones asociadas." << endl;
    cout << "Confirmar eliminación (s/n): ";
    cin >> confirmacion;
    
    if (confirmacion != 's' && confirmacion != 'S') {
        cout << "Operación cancelada. La película no fue eliminada." << endl;
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
        cout << "Película '" << titulo << "' eliminada exitosamente." << endl;
        return true;
    }
    
    cout << "Error: No se pudo eliminar la película." << endl;
    return false;
}

bool CEliminarPelicula::hayUsuarioLogueado() {
    Usuario* usuario = sesion->getUsuario();
    return (usuario != nullptr);
}

void CEliminarPelicula::eliminarFuncionesAsociadas(string tituloPelicula) {
    Pelicula* pelicula = manejadorPelicula->buscarPelicula(tituloPelicula);
    if (!pelicula) return;
    // Obtener todas las funciones
    list<Funcion*> funciones = manejadorFuncion->getFunciones();
    
    for (Funcion* funcion : funciones) {
        if (funcion->getPelicula() == pelicula) {
            // Eliminar las reservas asociadas a la función
            list<Reserva*> reservas = funcion->getReservas();
            for (Reserva* reserva : reservas) {
                delete reserva;
            }
            // Obtener el ID de la función antes de eliminarla
            int idFuncion = funcion->getIdFun();
            // Eliminar la función
            delete funcion;
        }
    }

    cout << "Se han eliminado todas las funciones y sus reservas para la película '" 
         << tituloPelicula << "'." << endl;
}

CEliminarPelicula::~CEliminarPelicula() {
    // No eliminar los manejadores ya que son singletons
}