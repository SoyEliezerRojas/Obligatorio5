#include "CCrearReserva.h"
#include "Sesion.h"

CCrearReserva::CCrearReserva() {
    this->peliculaSeleccionada = NULL;
    this->funcionSeleccionada = NULL;
    this->cantidadEntradas = 0;
    this->esDebito = false;
}

bool CCrearReserva::hayUsuarioLogueado() {
    return Sesion::getInstancia()->getUsuario() != NULL;
}

list<DtPelicula> CCrearReserva::listarPeliculas() {
    ManejadorPelicula* mP = ManejadorPelicula::getInstancia();
    list<DtPelicula> infoPeliculas;
    
    vector<Pelicula*>& peliculas = mP->getPeliculas();
    for(vector<Pelicula*>::iterator p = peliculas.begin(); p != peliculas.end(); ++p) {
        DtPelicula dtP = (*p)->getDtPelicula();
        infoPeliculas.push_back(dtP);
    }
    return infoPeliculas;
}

void CCrearReserva::selectPelicula(string titulo) {
    ManejadorPelicula* mP = ManejadorPelicula::getInstancia();
    this->peliculaSeleccionada = mP->buscarPelicula(titulo);
}

list<DtFuncion> CCrearReserva::listarFunciones() {
    list<DtFuncion> infoFunciones;
    if (this->peliculaSeleccionada != NULL) {
        ManejadorFuncion* mF = ManejadorFuncion::getInstancia();
        list<Funcion*> funciones = mF->getFunciones();
        
        for(list<Funcion*>::iterator f = funciones.begin(); f != funciones.end(); ++f) {
            // Solo mostrar funciones de la película seleccionada
            if ((*f)->getPelicula() == this->peliculaSeleccionada) {
                DtFuncion dtF((*f)->getIdFun(), (*f)->getDiaFun(), (*f)->getHoraFun());
                infoFunciones.push_back(dtF);
            }
        }
    }
    return infoFunciones;
}

void CCrearReserva::selectFuncion(int id) {
    ManejadorFuncion* mF = ManejadorFuncion::getInstancia();
    this->funcionSeleccionada = mF->buscarFuncion(id);
}

void CCrearReserva::ingresarCantidadEntradas(int cantidad) {
    this->cantidadEntradas = cantidad;
}

void CCrearReserva::seleccionarDebito(string banco) {
    this->banco = banco;
    this->esDebito = true;
}

void CCrearReserva::seleccionarCredito(string financiera, float descuento) {
    this->financiera = financiera;
    this->descuento = descuento;
    this->esDebito = false;
}

void CCrearReserva::confirmarReserva() {
    if (this->peliculaSeleccionada != NULL && this->funcionSeleccionada != NULL) {
        Usuario* usuarioActual = Sesion::getInstancia()->getUsuario();
        
        if (usuarioActual != NULL) {
            float costo = this->funcionSeleccionada->getPrecio() * this->cantidadEntradas;
            Reserva* reserva;
            
            // Generar un ID único para la reserva
            static int nextId = 1;
            int id = nextId++;
            
            if (this->esDebito) {
                reserva = new Debito(id, costo, this->cantidadEntradas, this->banco);
            } else {
                reserva = new Credito(id, costo, this->cantidadEntradas, this->descuento, this->financiera);
            }
            
            usuarioActual->agregarReserva(reserva);
            this->funcionSeleccionada->agregarReserva(reserva);
        }
    }
}

void CCrearReserva::cancelarReserva() {
    this->peliculaSeleccionada = NULL;
    this->funcionSeleccionada = NULL;
    this->cantidadEntradas = 0;
    this->esDebito = false;
}

CCrearReserva::~CCrearReserva() {
    // No necesitamos eliminar los punteros ya que son manejados por sus respectivos manejadores
    this->peliculaSeleccionada = NULL;
    this->funcionSeleccionada = NULL;
}
