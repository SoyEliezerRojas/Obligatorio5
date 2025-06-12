#ifndef CVERRESERVASDEPELICULA_H
#define CVERRESERVASDEPELICULA_H

#include "ICVerReservasDePelicula.h"
#include "ManejadorPelicula.h"
#include "ManejadorFuncion.h"
#include "Sesion.h"

class CVerReservasDePelicula : public ICVerReservasDePelicula {
    private:
        static CVerReservasDePelicula* instancia;
        string tituloSeleccionado;
        int idFuncionSeleccionada;
        CVerReservasDePelicula() {}
    public:
        static CVerReservasDePelicula* getInstancia();
        list<DtPelicula> listarPeliculas() override;
        void selectPelicula(string titulo) override;
        list<DtFuncion> listarFunciones() override;
        void selectFuncion(int idFuncion) override;
        list<DtReserva> listarReservas() override;
        list<DtReserva> listarReservasDePelicula(string titulo) override;
        ~CVerReservasDePelicula();
};

#endif
