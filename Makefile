main: DtFecha.o DtHorario.o DtDireccion.o Sala.o Cine.o Funcion.o Pelicula.o Usuario.o Reserva.o Debito.o Credito.o DtSala.o DtCine.o DtFuncion.o DtPelicula.o DtPeliFull.o DtReserva.o Sesion.o CIniciarSesion.o CCerrarSesion.o Fabrica.o Puntaje.o DtPuntaje.o Comentario.o DtComentario.o ManejadorUsuario.o CAltaUsuario.o ManejadorPelicula.o CAltaPelicula.o ManejadorCine.o CAltaCine.o ManejadorFuncion.o CAltaFuncion.o CPuntuarPelicula.o CComentarPelicula.o CCrearReserva.o CEliminarPelicula.o CVerReservasDePelicula.o CVerInformacionPelicula.o CVerComentariosyPuntajesdePelicula.o Reloj.o CReloj.o Financiera.o ManejadorFinanciera.o main.o
	g++ DtFecha.o DtHorario.o DtDireccion.o Sala.o Cine.o Funcion.o Pelicula.o Usuario.o Reserva.o Debito.o Credito.o DtSala.o DtCine.o DtFuncion.o DtPelicula.o DtPeliFull.o DtReserva.o Sesion.o CIniciarSesion.o CCerrarSesion.o Fabrica.o Puntaje.o DtPuntaje.o Comentario.o DtComentario.o ManejadorUsuario.o CAltaUsuario.o ManejadorPelicula.o CAltaPelicula.o ManejadorCine.o CAltaCine.o ManejadorFuncion.o CAltaFuncion.o CPuntuarPelicula.o CComentarPelicula.o CCrearReserva.o CEliminarPelicula.o CVerReservasDePelicula.o CVerInformacionPelicula.o CVerComentariosyPuntajesdePelicula.o Reloj.o CReloj.o Financiera.o ManejadorFinanciera.o main.o -o mainCine

DtPeliFull.o: DtPeliFull.cpp

CVerComentariosyPuntajesdePelicula.o: CVerComentariosyPuntajesdePelicula.cpp

DtReserva.o: DtReserva.cpp

DtPelicula.o: DtPelicula.cpp

DtFuncion.o: DtFuncion.cpp

DtCine.o: DtCine.cpp

DtSala.o: DtSala.cpp

Credito.o: Credito.cpp

Debito.o: Debito.cpp

Reserva.o: Reserva.cpp

Usuario.o: Usuario.cpp

Pelicula.o: Pelicula.cpp

Funcion.o: Funcion.cpp

Cine.o: Cine.cpp

Sala.o: Sala.cpp

DtDireccion.o: DtDireccion.cpp

DtHorario.o: DtHorario.cpp

DtFecha.o: DtFecha.cpp

Sesion.o: Sesion.cpp

CIniciarSesion.o: CIniciarSesion.cpp

CCerrarSesion.o: CCerrarSesion.cpp

Fabrica.o: Fabrica.cpp

Puntaje.o: Puntaje.cpp

DtPuntaje.o: DtPuntaje.cpp

Comentario.o: Comentario.cpp

DtComentario.o: DtComentario.cpp

ManejadorUsuario.o: ManejadorUsuario.cpp

CAltaUsuario.o: CAltaUsuario.cpp

CAltaPelicula.o: CAltaPelicula.cpp

ManejadorPelicula.o: ManejadorPelicula.cpp

ManejadorCine.o: ManejadorCine.cpp

CAltaCine.o: CAltaCine.cpp

ManejadorFuncion.o: ManejadorFuncion.cpp

CAltaFuncion.o: CAltaFuncion.cpp

CPuntuarPelicula.o: CPuntuarPelicula.cpp

CCrearReserva.o: CCrearReserva.cpp

CComentarPelicula.o: CComentarPelicula.cpp

CEliminarPelicula.o: CEliminarPelicula.cpp

CVerReservasDePelicula.o: CVerReservasDePelicula.cpp

CVerInformacionPelicula.o: CVerInformacionPelicula.cpp

Reloj.o: Reloj.cpp

CReloj.o: CReloj.cpp

main.o: main.cpp

Financiera.o: Financiera.cpp

ManejadorFinanciera.o: ManejadorFinanciera.cpp

clean:
	rm -f *.o mainCine