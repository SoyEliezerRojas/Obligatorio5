main: DtFecha.o DtHorario.o DtDireccion.o Sala.o Cine.o Funcion.o Pelicula.o Usuario.o Reserva.o Debito.o Credito.o DtSala.o DtCine.o DtFuncion.o DtPelicula.o DtReserva.o Sesion.o CIniciarSesion.o CCerrarSesion.o Fabrica.o main.o
	g++ DtFecha.o DtHorario.o DtDireccion.o Sala.o Cine.o Funcion.o Pelicula.o Usuario.o Reserva.o Debito.o Credito.o DtSala.o DtCine.o DtFuncion.o DtPelicula.o DtReserva.o Sesion.o CIniciarSesion.o CCerrarSesion.o Fabrica.o main.o -o mainCine

DtReserva.o: DtReserva.cpp
	g++ -c DtReserva.cpp

DtPelicula.o: DtPelicula.cpp
	g++ -c DtPelicula.cpp

DtFuncion.o: DtFuncion.cpp
	g++ -c DtFuncion.cpp

DtCine.o: DtCine.cpp
	g++ -c DtCine.cpp

DtSala.o: DtSala.cpp
	g++ -c DtSala.cpp

Credito.o: Credito.cpp
	g++ -c Credito.cpp

Debito.o: Debito.cpp
	g++ -c Debito.cpp

Reserva.o: Reserva.cpp
	g++ -c Reserva.cpp

Usuario.o: Usuario.cpp
	g++ -c Usuario.cpp

Pelicula.o: Pelicula.cpp
	g++ -c Pelicula.cpp

Funcion.o: Funcion.cpp
	g++ -c Funcion.cpp

Cine.o: Cine.cpp
	g++ -c Cine.cpp

Sala.o: Sala.cpp
	g++ -c Sala.cpp

DtDireccion.o: DtDireccion.cpp
	g++ -c DtDireccion.cpp

DtHorario.o: DtHorario.cpp
	g++ -c DtHorario.cpp

DtFecha.o: DtFecha.cpp
	g++ -c DtFecha.cpp

Sesion.o: Sesion.cpp
	g++ -c Sesion.cpp

CIniciarSesion.o: CIniciarSesion.cpp
	g++ -c CIniciarSesion.cpp

CCerrarSesion.o: CCerrarSesion.cpp
	g++ -c CCerrarSesion.cpp

Fabrica.o: Fabrica.cpp
	g++ -c Fabrica.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *.o mainCine
