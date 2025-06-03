main: DtFecha.o DtHorario.o DtDireccion.o Sala.o Cine.o Funcion.o Pelicula.o Usuario.o Reserva.o Debito.o Credito.o DtSala.o DtCine.o  main.o
	g++ DtFecha.o DtHorario.o DtDireccion.o Sala.o Cine.o Funcion.o Pelicula.o Usuario.o Reserva.o Debito.o Credito.o DtSala.o DtCine.o main.o -o mainCine

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


main.o: main.cpp

clean:
	rm -rf *.o mainCine
