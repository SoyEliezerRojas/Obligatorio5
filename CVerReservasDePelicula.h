#ifndef CVERRESERVASDEPELICULA_H
#define CVERRESERVASDEPELICULA_H

#include "ICVerReservasDePelicula.h"
#include "ManejadorPelicula.h"
#include "ManejadorFuncion.h"
#include "Sesion.h"

class CVerReservasDePelicula : public ICVerReservasDePelicula {
    private:
        static CVerReservasDePelicula* instancia;
        CVerReservasDePelicula();
    public:
        static CVerReservasDePelicula* getInstancia();
        list<DtPelicula> listarPeliculas() override;
        list<DtFuncion> obtenerFuncionesDePelicula(string titulo) override;
        list<DtReserva> obtenerReservasDeFuncion(int idFuncion) override;
        ~CVerReservasDePelicula();
};

#endif
