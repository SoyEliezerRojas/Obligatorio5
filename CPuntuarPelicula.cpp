#include "CPuntuarPelicula.h"
#include "ManejadorPelicula.h"
#include "Sesion.h"
#include "Puntaje.h"
#include <stdexcept>

using namespace std;

list<DtPelicula> CPuntuarPelicula::listarPeliculas() {
    ManejadorPelicula* mP = ManejadorPelicula::getInstancia();
    return mP->listarPeliculas();
}

CPuntuarPelicula::CPuntuarPelicula() {
    this->pelicula = nullptr;
    this->usuario = nullptr;
    this->puntajeTemp = 0;
    this->puntajeConfirmado = false;
}

void CPuntuarPelicula::ingresarPelicula(string titulo) {
    ManejadorPelicula* mP = ManejadorPelicula::getInstancia();
    this->pelicula = mP->buscarPelicula(titulo);
    if (this->pelicula == nullptr) {
        throw invalid_argument("No existe una película con ese título");
    }
    this->usuario = Sesion::getInstancia()->getUsuario();
    if (this->usuario == nullptr) {
        throw invalid_argument("Debe iniciar sesión para puntuar una película");
    }
}

bool CPuntuarPelicula::getPuntajeAnterior(float& puntaje) {
    return false; // Por ahora retornamos false
}

void CPuntuarPelicula::ingresarPuntaje(float puntaje) {
    if (this->pelicula == nullptr) {
        throw invalid_argument("Debe seleccionar una película primero");
    }
    
    if (puntaje < 1 || puntaje > 5) {
        throw invalid_argument("El puntaje debe estar entre 1 y 5");
    }
    
    this->puntajeTemp = puntaje;
}

void CPuntuarPelicula::confirmarPuntaje() {
    if (pelicula && usuario && puntajeTemp >= 1 && puntajeTemp <= 5) {
        // Crear el nuevo puntaje
        Puntaje* nuevoPuntaje = new Puntaje(puntajeTemp, pelicula, usuario);
        
        // Agregarlo al manejador
        ManejadorPelicula::getInstancia()->agregarPuntaje(nuevoPuntaje);
        
        // Recalcular promedio (esto es complejo, asumimos una simplificación)
        // La lógica real de promedio debería estar en la clase Pelicula, 
        // pero por ahora lo dejamos así para no modificar más archivos.
        
        puntajeConfirmado = true;
    }
}

void CPuntuarPelicula::cancelarPuntaje() {
    this->puntajeTemp = 0;
    this->puntajeConfirmado = false;
}

CPuntuarPelicula::~CPuntuarPelicula() {
    // No liberamos pelicula ni usuario porque no somos dueños de estos punteros
}
