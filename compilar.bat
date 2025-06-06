@echo off
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
cl.exe /EHsc /W4 /std:c++17 /Fe:programa.exe ^
    main.cpp ^
    Fabrica.cpp ^
    CIniciarSesion.cpp ^
    CCerrarSesion.cpp ^
    Sesion.cpp ^
    Usuario.cpp ^
    Sala.cpp ^
    Reserva.cpp ^
    Puntaje.cpp ^
    Pelicula.cpp ^
    ManejadorUsuario.cpp ^
    Funcion.cpp ^
    DtSala.cpp ^
    DtReserva.cpp ^
    DtPuntaje.cpp ^
    DtPelicula.cpp ^
    DtHorario.cpp ^
    DtFuncion.cpp ^
    DtFecha.cpp ^
    DtDireccion.cpp ^
    DtComentario.cpp ^
    DtCine.cpp ^
    Debito.cpp ^
    Credito.cpp ^
    Controlador.cpp ^
    Comentario.cpp ^
    Cine.cpp ^
    CAltaUsuario.cpp 