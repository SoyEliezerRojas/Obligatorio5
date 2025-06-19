#ifndef CCREARRESERVA_H
#define CCREARRESERVA_H

#include "ICCrearReserva.h"
#include "ManejadorPelicula.h"
#include "ManejadorFuncion.h"
#include "ManejadorUsuario.h"
#include "ManejadorFinanciera.h"
#include "Pelicula.h"
#include "Funcion.h"
#include "Usuario.h"
#include "Reserva.h"
#include "Debito.h"
#include "Credito.h"
#include "DtPelicula.h"
#include "DtFuncion.h"

class CCrearReserva : public ICCrearReserva {
private:
    Pelicula* peliculaSeleccionada;
    Funcion* funcionSeleccionada;
    int cantidadEntradas;
    bool esDebito;
    string banco;
    string financiera;
    float descuento;

public:
    CCrearReserva();
    bool hayUsuarioLogueado();
    list<DtPelicula> listarPeliculas();
    void selectPelicula(string titulo);
    list<DtFuncion> listarFunciones();
    void selectFuncion(int id);
    void ingresarCantidadEntradas(int cantidad);
    void seleccionarDebito(string banco);
    float obtenerDescuentoFinanciera(string financiera);
    void seleccionarCredito(string financiera);
    float calcularPrecioTotal();
    void confirmarReserva();
    void cancelarReserva();
    ~CCrearReserva();
};

#endif
