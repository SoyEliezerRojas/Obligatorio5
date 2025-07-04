#include <iostream>
#include <stdexcept>
#include "Fabrica.h"
#include "Sesion.h"
#include "Usuario.h"
#include "ICIniciarSesion.h"
#include "ICCerrarSesion.h"
#include "ICAltaUsuario.h"
#include "ICAltaPelicula.h"
#include "ICAltaCine.h"
#include "ICAltaFuncion.h"
#include "ICPuntuarPelicula.h"
#include "ICCrearReserva.h"
#include "ICComentarPelicula.h"
#include "ICEliminarPelicula.h"
#include "DtDireccion.h"
#include "DtPelicula.h"
#include "DtCine.h"
#include "DtSala.h"
#include "DtFuncion.h"
#include "DtFecha.h"
#include "DtHorario.h"
#include "ICVerReservasDePelicula.h"
#include "ICVerInformacionPelicula.h"
#include "ICReloj.h"
#include "ICVerComentariosyPuntajesdePelicula.h"
using namespace std;

// Constantes para colores ANSI
const string COLOR_GREEN = "\033[32m";
const string COLOR_MAGENTA = "\033[35m";
const string COLOR_RESET = "\033[0m";

void mostrarEncabezado(string titulo) {
    system("clear");
    Sesion* sesion = Sesion::getInstancia();
    Usuario* usuarioLogueado = sesion->getUsuario();

    if (usuarioLogueado != nullptr) {
        cout << COLOR_MAGENTA << "Usuario logueado: " << usuarioLogueado->getNickName() << COLOR_RESET << endl;
        cout << "---------------------------------" << endl;
    }
    cout << "_" << endl;
    cout << "_" << COLOR_GREEN << titulo << COLOR_RESET << "_" << endl;
}

Fabrica* fabrica;
ICAltaUsuario* iAltaUsuario;
ICIniciarSesion* iIniciarSesion;
ICCerrarSesion* iCerrarSesion;
ICAltaPelicula* iAltaPelicula;
ICAltaCine* iAltaCine;
ICAltaFuncion* iAltaFuncion;
ICPuntuarPelicula* iPuntuarPelicula;
ICCrearReserva* iCrearReserva;
ICComentarPelicula* iComentarPelicula;
ICEliminarPelicula* iEliminarPelicula;
ICVerReservasDePelicula* iVerReservasDePelicula;
ICVerInformacionPelicula* iVerInformacionPelicula;
ICReloj* iReloj;
ICVerComentariosyPuntajesdePelicula* iVerComentariosyPuntajesdePelicula;

void altaUsuario(){
    mostrarEncabezado("A L T A  D E  U S U A R I O");
    
    string nickname, contrasenia, url;
    int aux;
    bool nicknameDisponible = false;
    
    do {
        cout << "NICKNAME: ";
        cin >> nickname;
        
        nicknameDisponible = iAltaUsuario->verificarNickname(nickname);
        
        if (!nicknameDisponible) {
            cout << "ERROR: El nickname ya está en uso." << endl;
            cout << "1. Reintentar" << endl;
            cout << "2. Cancelar" << endl;
            cout << "Opción: ";
            cin >> aux;
            
            if (aux == 2) {
                cout << "Operación cancelada." << endl;
                return;
            }
        }
    } while (!nicknameDisponible);
    
    cout << endl << "PASSWORD: ";
    cin >> contrasenia;
    
    cout << "¿DESEA INGRESAR FOTO DEL PERFIL? 1: SI 2:NO"<<endl;
    cin >> aux;
    if(aux == 1){
        cout << "URL FOTO DEL PERFIL: ";
        cin >> url;
    }else{
        url = "";
    }
    
    iAltaUsuario->altaUsuario(nickname, contrasenia, url);
    
    // Mostrar información del socio registrado
    cout << endl << "SE HA REGISTRADO EL SOCIO:" << endl;
    cout << " NickName: " << nickname << endl;
    cout << " PASS: " << contrasenia << endl;
    cout << " URL: " << url << endl;
}

void iniciarSesion() {
    mostrarEncabezado("I N I C I A R  S E S I O N");

    Sesion* sesion = Sesion::getInstancia();
    if (sesion->getUsuario() != nullptr) {
        cout << endl << "ERROR: Ya hay una sesión iniciada." << endl;
        cout << "Por favor, cierre la sesión actual para iniciar con otro usuario." << endl;
        return;
    }
    
    string nickname, password;
    bool passwordValida = false;
    int opcion;
    
    // 1. Pedir nickname (según diagrama)
    cout << "NICKNAME: ";
    cin >> nickname;
    iIniciarSesion->ingresarNick(nickname);  // El sistema recuerda el nick
    
    // 2. Loop de validación de contraseña (según diagrama)
    do {
        cout << "PASSWORD: ";
        cin >> password;
        
        passwordValida = iIniciarSesion->verificarPas(password);
        
        if (!passwordValida) {
            cout << "Contraseña incorrecta." << endl;
            cout << "1. Reintentar" << endl;
            cout << "2. Cancelar" << endl;
            cout << "Opción: ";
            cin >> opcion;
            
            if (opcion != 1) {  // Si no es 1 (reintentar), cancelar
                cout << "Operación cancelada." << endl;
                return;
            }
        }
        
    } while (!passwordValida);
    
    // 3. Si llegamos aquí, iniciar sesión
    iIniciarSesion->iniciarSesion();  // Conecta usuario a la sesión
    cout << endl << "SESION INICIADA CORRECTAMENTE" << endl;
}

void cerrarSesion() {
    mostrarEncabezado("C E R R A R  S E S I O N");
    
    if(iCerrarSesion->cerrarSesion()) {
        cout << endl << "SESION CERRADA CORRECTAMENTE" << endl;
    } else {
        cout << endl << "ERROR: NO HAY SESION INICIADA" << endl;
    }
}

void altaPelicula() {
    mostrarEncabezado("A L T A  D E  P E L I C U L A");
    
    if (!iAltaPelicula->hayUsuarioLogueado()) {
        cout << "ERROR: Debe iniciar sesión para dar de alta una película." << endl;
        return;
    }
    
    string titulo, sinopsis, url;
    int opcion;
    while (true) {
        cout << "TITULO: ";
        cin.ignore();
        getline(cin, titulo);
        if (iAltaPelicula->verificarExistenciaPelicula(titulo)) {
            cout << "ERROR: Ya existe una película con ese título." << endl;
            cout << "1. Reintentar" << endl;
            cout << "2. Cancelar" << endl;
            cout << "Opción: ";
            cin >> opcion;
            if (opcion == 2) {
                cout << "Operación cancelada." << endl;
                return;
            }
        } else {
            break;
        }
    }
    cout << endl << "SINOPSIS: ";
    getline(cin, sinopsis);
    cout << endl << "URL DEL POSTER: ";
    getline(cin, url);
    iAltaPelicula->altaPelicula(titulo, sinopsis, url);
    cout << endl << "PELICULA REGISTRADA CORRECTAMENTE" << endl;
}

void altaCine() {
    mostrarEncabezado("A L T A  D E  C I N E");
    
    // Verificar si hay usuario logueado
    if (!iAltaCine->hayUsuarioLogueado()) {
        cout << "ERROR: Debe iniciar sesión para dar de alta un cine." << endl;
        return;
    }
    
    // Obtener el ID que se asignará
    int nextId = iAltaCine->getNextId();
    cout << "ID del nuevo cine: " << nextId << endl << endl;
    
    // Ingresar dirección
    string calle;
    int numero;
    cout << "DIRECCION DEL CINE" << endl;
    cout << "Calle: ";
    cin.ignore();
    getline(cin, calle);
    cout << "Numero: ";
    cin >> numero;
    
    DtDireccion direccion(calle, numero);
    iAltaCine->ingresarDireccion(direccion);
    
    // Ingresar capacidades de salas
    list<int> capacidades;
    int cantSalas;
    cout << endl << "Cantidad de salas: ";
    cin >> cantSalas;
    
    for(int i = 1; i <= cantSalas; i++) {
        int capacidad;
        cout << "Capacidad de la sala " << i << ": ";
        cin >> capacidad;
        capacidades.push_back(capacidad);
    }
    
    iAltaCine->ingresarCapacidades(capacidades);
    
    // Solicitar confirmación
    cout << endl << "¿Desea confirmar el alta del cine? (1: SI, 2: NO): ";
    int confirmar;
    cin >> confirmar;
    
    if (confirmar == 1) {
        // Dar de alta el cine
        iAltaCine->altaCine();
        cout << endl << "CINE " << nextId << " REGISTRADO CORRECTAMENTE" << endl;
        cout << "Direccion: " << calle << " " << numero << endl;
        cout << "Cantidad de salas: " << cantSalas << endl;
    } else {
        cout << endl << "OPERACION CANCELADA" << endl;
    }
}

void altaFuncion() {
    mostrarEncabezado("A L T A  D E  F U N C I O N");

    // Verificar si hay usuario logueado
    if (!iAltaFuncion->hayUsuarioLogueado()) {
        cout << "ERROR: Debe iniciar sesión para dar de alta una función." << endl;
        return;
    }

    // Listar películas disponibles
    list<DtPelicula> peliculas = iAltaFuncion->listarPeliculas();
    if (peliculas.empty()) {
        cout << "No hay películas registradas en el sistema." << endl;
        return;
    }

    cout << "PELÍCULAS DISPONIBLES:" << endl;
    for (list<DtPelicula>::iterator it = peliculas.begin(); it != peliculas.end(); ++it) {
        cout << "- " << it->getTitulo() << endl;
    }

    // Seleccionar película
    string titulo;
    cout << endl << "Ingrese el título de la película: ";
    cin.ignore();
    getline(cin, titulo);
    iAltaFuncion->selectPeli(titulo);

    char continuar;
    do {
        // Listar cines disponibles (MOVIDO DENTRO DEL LOOP)
        list<DtCine> cines = iAltaFuncion->listarCines();
        if (cines.empty()) {
            cout << "No hay cines registrados en el sistema." << endl;
            return;
        }

        cout << endl << "CINES DISPONIBLES:" << endl;
        for (list<DtCine>::iterator it = cines.begin(); it != cines.end(); ++it) {
            cout << "ID: " << it->getId() << " - Dirección: " << it->getDireccion().getCalle() 
                 << " " << it->getDireccion().getNumero() << endl;
        }

        // Seleccionar cine (MOVIDO DENTRO DEL LOOP)
        string idCine;
        cout << endl << "Ingrese el ID del cine: ";
        cin >> idCine;
        iAltaFuncion->selectCine(idCine);

        // Listar salas del cine con información detallada
        list<DtSala> salas = iAltaFuncion->listarSalas();
        if (salas.empty()) {
            cout << "No hay salas disponibles en este cine." << endl;
            continue; // Cambiar return por continue para permitir elegir otro cine
        }

        // Mostrar información detallada de salas con ocupación
        list<DtSala> salasConOcupacion = iAltaFuncion->obtenerSalasConOcupacion();
        map<int, string> ocupacionSalas = iAltaFuncion->obtenerInformacionOcupacionSalas();
        
        cout << endl << "SALAS DISPONIBLES:" << endl;
        for (list<DtSala>::iterator it = salasConOcupacion.begin(); it != salasConOcupacion.end(); ++it) {
            cout << "ID: " << it->getId() << " - Capacidad: " << it->getCapacidad() << " asientos";
            
            // Buscar información de ocupación para esta sala
            map<int, string>::iterator ocupacionIt = ocupacionSalas.find(it->getId());
            if (ocupacionIt != ocupacionSalas.end() && !ocupacionIt->second.empty()) {
                cout << " - Ocupado para: " << ocupacionIt->second;
            }
            cout << endl;
        }

        // Seleccionar sala
        int idSala;
        cout << endl << "Ingrese el ID de la sala: ";
        cin >> idSala;
        iAltaFuncion->selectSala(idSala);

        // Ingresar datos de la función
        string horaInicio;
        int dia, mes, anio;
        
        cout << endl << "DATOS DE LA FUNCIÓN" << endl;
        cout << "Hora de inicio (HH:MM): ";
        cin >> horaInicio;
        cout << "Fecha (DD MM AAAA): ";
        cin >> dia >> mes >> anio;

        DtFecha fecha(dia, mes, anio);
        iAltaFuncion->altaFuncion(horaInicio, fecha);
        
        cout << endl << "FUNCIÓN CREADA EXITOSAMENTE" << endl;
        
        cout << endl << "¿Desea agregar otra función para esta película? (s/n): ";
        cin >> continuar;
        
    } while (tolower(continuar) == 's');
}

void comentarPelicula() {
    mostrarEncabezado("C O M E N T A R  P E L I C U L A");

    if (!iComentarPelicula->hayUsuarioLogueado()) {
        cout << "ERROR: Debe iniciar sesión para comentar una película." << endl;
        return;
    }

    try {
        // Listar películas
        cout << "PELÍCULAS DISPONIBLES:" << endl;
        list<DtPelicula> peliculas = iComentarPelicula->listarPeliculas();
        for (list<DtPelicula>::iterator it = peliculas.begin(); it != peliculas.end(); ++it) {
            cout << "- " << it->getTitulo() << endl;
        }

        // Seleccionar película
        string titulo;
        cout << endl << "Ingrese el título de la película: ";
        cin.ignore(10000, '\n');
        getline(cin, titulo);
        iComentarPelicula->selectPeli(titulo);

        // Mostrar comentarios existentes de la película seleccionada
        cout << endl << "========================================" << endl;
        cout << "COMENTARIOS EXISTENTES PARA: " << titulo << endl;
        cout << "========================================" << endl;
        


        char continuar;
        do {
            list<DtComentario*> comentarios = iComentarPelicula->obtenerComentariosPeliculaSeleccionada();
            vector<int> idsReales = iComentarPelicula->obtenerIdsComentariosPeliculaSeleccionada();
        if (comentarios.empty()) {
            cout << "No hay comentarios para esta película." << endl;
        } else {
            int indice = 0;
            for (list<DtComentario*>::iterator it = comentarios.begin(); it != comentarios.end(); ++it) {
                cout << "[ID: " << idsReales[indice] << "] " << (*it)->getNickname() << ": " << (*it)->getTexto() << endl;
                
                // Mostrar respuestas con indentación
                set<DtComentario*> respuestas = (*it)->getRespuestas();
                for (set<DtComentario*>::iterator itResp = respuestas.begin(); itResp != respuestas.end(); ++itResp) {
                    cout << "           " << (*itResp)->getNickname() << ": " << (*itResp)->getTexto() << endl;
                }
                indice++;
            }
        }
            cout << endl << "¿Qué desea hacer?" << endl;
            cout << "1. Agregar nuevo comentario" << endl;
            cout << "2. Responder a un comentario" << endl;
            cout << "3. Volver al menú principal" << endl;
            cout << "Opción: ";

            int opcion;
            cin >> opcion;
            cin.ignore(10000, '\n');

            string texto;
            switch(opcion) {
                case 1:
                    cout << "Ingrese su comentario: ";
                    getline(cin, texto);
                    iComentarPelicula->comentar(texto);
                    cout << "Comentario agregado exitosamente" << endl;
                    break;

                case 2:
                    int idComentario;
                    cout << "Ingrese el ID del comentario a responder: ";
                    cin >> idComentario;
                    cin.ignore(10000, '\n');
                    cout << "Ingrese su respuesta: ";
                    getline(cin, texto);
                    iComentarPelicula->responder(idComentario, texto);
                    cout << "Respuesta agregada exitosamente" << endl;
                    break;

                case 3:
                    return;

                default:
                    cout << "Opción inválida" << endl;
                    continue;
            }

            cout << endl << "¿Desea agregar otro comentario? (s/n): ";
            cin >> continuar;




        } while (tolower(continuar) == 's');

    } catch (const invalid_argument& e) {
        cout << "ERROR: " << e.what() << endl;
    }
}

void puntuarPelicula() {
    mostrarEncabezado("P U N T U A R  P E L I C U L A");
    
    // Listar películas disponibles
    list<DtPelicula> peliculas = iPuntuarPelicula->listarPeliculas();
    if (peliculas.empty()) {
        cout << "No hay películas registradas en el sistema." << endl;
        return;
    }

    cout << "PELÍCULAS DISPONIBLES:" << endl;
    for (list<DtPelicula>::iterator it = peliculas.begin(); it != peliculas.end(); ++it) {
        cout << "- " << it->getTitulo() << endl;
    }

    string titulo;
    int puntaje;

    cout << endl << "TITULO DE LA PELICULA: ";
    cin.ignore();
    getline(cin, titulo);

    try {
        iPuntuarPelicula->ingresarPelicula(titulo);

        cout << "PUNTAJE (1-5): ";
        cin >> puntaje;

        if (puntaje < 1 || puntaje > 5) {
            cout << "ERROR: El puntaje debe estar entre 1 y 5" << endl;
            return;
        }

        iPuntuarPelicula->ingresarPuntaje(puntaje);

        cout << "¿DESEA CONFIRMAR EL PUNTAJE? (1: SI, 2: NO): ";
        int confirmar;
        cin >> confirmar;

        if (confirmar == 1) {
            iPuntuarPelicula->confirmarPuntaje();
            cout << "PUNTAJE REGISTRADO CORRECTAMENTE" << endl;
        } else {
            iPuntuarPelicula->cancelarPuntaje();
            cout << "OPERACION CANCELADA" << endl;
        }
    } catch (const invalid_argument& e) {
        cout << "ERROR: " << e.what() << endl;
    }
}

void crearReserva() {
    mostrarEncabezado("C R E A R  R E S E R V A");

    if (!iCrearReserva->hayUsuarioLogueado()) {
        cout << "ERROR: Debe iniciar sesión para crear una reserva." << endl;
        return;
    }

    list<DtPelicula> peliculas = iCrearReserva->listarPeliculas();
    if (peliculas.empty()) {
        cout << "No hay películas disponibles para reservar." << endl;
        return;
    }

    cout << "PELÍCULAS DISPONIBLES:" << endl;
    for (list<DtPelicula>::iterator it = peliculas.begin(); it != peliculas.end(); ++it) {
        cout << "- " << it->getTitulo() << endl;
    }

    string titulo;
    cout << endl << "Ingrese el título de la película (o '1' para cancelar): ";
    cin.ignore();
    getline(cin, titulo);

    if (titulo == "1") {
        cout << "Operación cancelada." << endl;
        return;
    }

    try {
        DtPelicula dtp = iVerInformacionPelicula->obtenerInformacionPelicula(titulo);
        cout << endl << "========================================" << endl;
        cout << "PÓSTER: " << dtp.getPoster() << endl;
        cout << "SINOPSIS: " << dtp.getSinopsis() << endl;
        cout << "========================================" << endl;

        cout << endl << "¿Qué desea hacer?" << endl;
        cout << "1. Ver información de cines y funciones" << endl;
        cout << "2. Finalizar" << endl;
        cout << "Opción: ";
        int opcion;
        cin >> opcion;

        if (opcion != 1) {
            cout << "Operación finalizada." << endl;
            return;
        }
        
        iCrearReserva->selectPelicula(titulo);

        list<DtCine> cines = iVerInformacionPelicula->obtenerCinesPelicula(titulo);
        if (cines.empty()) {
            cout << "Esta película no se proyecta en ningún cine actualmente." << endl;
            return;
        }

        cout << endl << "CINES DONDE SE PROYECTA '" << titulo << "':" << endl;
        for (list<DtCine>::iterator it = cines.begin(); it != cines.end(); ++it) {
            cout << "ID: " << it->getId() << " - Dirección: " << it->getDireccion().getCalle() << " " << it->getDireccion().getNumero() << endl;
        }

        cout << endl << "¿Desea seleccionar un cine para ver las funciones? (s/n): ";
        char respuesta;
        cin >> respuesta;

        if (respuesta != 's' && respuesta != 'S') {
            cout << "Operación cancelada." << endl;
            return;
        }

        int idCine;
        cout << "Ingrese el ID del cine: ";
        cin >> idCine;

        list<DtFuncion> funciones = iVerInformacionPelicula->obtenerFuncionesPeliculaEnCine(titulo, idCine);
        if (funciones.empty()) {
            cout << "No hay funciones disponibles para esta película en este cine." << endl;
            return;
        }

        cout << endl << "FUNCIONES DISPONIBLES (posteriores a la fecha actual):" << endl;
        for (list<DtFuncion>::iterator it = funciones.begin(); it != funciones.end(); ++it) {
            cout << "ID: " << it->getIdFun() << " - Fecha: " << it->getDiaFun().getDia() << "/"
                 << it->getDiaFun().getMes() << "/" << it->getDiaFun().getAnio()
                 << " - Hora: " << it->getHoraFun().getHoraIni() << endl;
        }

        int idFuncion;
        cout << endl << "Ingrese el ID de la función: ";
        cin >> idFuncion;
        iCrearReserva->selectFuncion(idFuncion);

        int cantEntradas;
        int asientosDisponibles = iCrearReserva->obtenerAsientosDisponibles();

        if (asientosDisponibles <= 0) {
            cout << "Lo sentimos, no quedan asientos disponibles para esta función." << endl;
            return;
        }

        do {
            cout << endl << "Asientos disponibles: " << asientosDisponibles << endl;
            cout << "Cantidad de entradas a reservar: ";
            cin >> cantEntradas;

            if (cantEntradas <= 0 || cantEntradas > asientosDisponibles) {
                cout << "Error: La cantidad de entradas debe ser mayor que 0 y no puede superar los asientos disponibles." << endl;
            }
        } while (cantEntradas <= 0 || cantEntradas > asientosDisponibles);
        
        iCrearReserva->ingresarCantidadEntradas(cantEntradas);

        cout << endl << "FORMA DE PAGO:" << endl;
        cout << "1. Débito" << endl;
        cout << "2. Crédito" << endl;
        int opcionPago;
        cout << "Seleccione una opción (1-2): ";
        cin >> opcionPago;

        if (opcionPago == 1) {
            string banco;
            cout << "Ingrese el banco: ";
            cin.ignore();
            getline(cin, banco);
            iCrearReserva->seleccionarDebito(banco);
        } else if (opcionPago == 2) {
            string financiera;
            cout << "Ingrese la financiera: ";
            cin.ignore();
            getline(cin, financiera);

            float descuento = iCrearReserva->obtenerDescuentoFinanciera(financiera);
            if (descuento > 0) {
                cout << "La financiera " << financiera << " tiene un descuento del " << descuento << "%" << endl;
            } else {
                cout << "La financiera " << financiera << " no tiene descuento" << endl;
            }
            iCrearReserva->seleccionarCredito(financiera);
        }

        float precioTotal = iCrearReserva->calcularPrecioTotal();
        cout << endl << "PRECIO TOTAL: $" << precioTotal << endl;

        cout << endl << "¿Desea confirmar la reserva? (1: SI, 2: NO): ";
        int confirmar;
        cin >> confirmar;

        if (confirmar == 1) {
            iCrearReserva->confirmarReserva();
            cout << "RESERVA CREADA EXITOSAMENTE" << endl;
        } else {
            iCrearReserva->cancelarReserva();
            cout << "OPERACIÓN CANCELADA" << endl;
        }
    } catch (const invalid_argument& e) {
        cout << "ERROR: " << e.what() << endl;
    }
}

void eliminarPelicula() {
    mostrarEncabezado("E L I M I N A R  P E L I C U L A");

    if (!iEliminarPelicula->hayUsuarioLogueado()) {
        cout << "ERROR: Debe iniciar sesión para eliminar una película." << endl;
        return;
    }

    // Listar películas disponibles
    list<DtPelicula> peliculas = iEliminarPelicula->listarPeliculas();
    if (peliculas.empty()) {
        cout << "No hay películas registradas en el sistema." << endl;
        return;
    }

    cout << "PELÍCULAS DISPONIBLES:" << endl;
    for (list<DtPelicula>::iterator it = peliculas.begin(); it != peliculas.end(); ++it) {
        cout << "- " << it->getTitulo() << endl;
    }
    
    // Seleccionar película a eliminar
    string titulo;
    cout << endl << "Ingrese el título de la película a eliminar: ";
    cin.ignore();
    getline(cin, titulo);

    // Obtener información de la película
    try {
        DtPelicula pelicula = iEliminarPelicula->obtenerInformacionPelicula(titulo);

        // Mostrar información de la película a eliminar
        cout << endl << "=== PELÍCULA A ELIMINAR ===" << endl;
        cout << "Título: " << pelicula.getTitulo() << endl;
        cout << "Sinopsis: " << pelicula.getSinopsis() << endl;
        cout << "Póster: " << pelicula.getPoster() << endl;
        cout << "============================" << endl;
        
        // Pedir confirmación
        char confirmacion;
        cout << endl << "¿Está seguro de que desea eliminar esta película?" << endl;
        cout << "ADVERTENCIA: Se eliminarán todas las funciones asociadas." << endl;
        cout << "Confirmar eliminación (s/n): ";
        cin >> confirmacion;
        
        if (confirmacion != 's' && confirmacion != 'S') {
            cout << "Operación cancelada. La película no fue eliminada." << endl;
            return;
        }

        // Intentar eliminar la película
        if (iEliminarPelicula->eliminarPelicula(titulo)) {
            cout << "Película '" << titulo << "' eliminada exitosamente." << endl;
            cout << "Se han eliminado todas las funciones y sus reservas para la película." << endl;
        } else {
            cout << "ERROR: No se pudo eliminar la película." << endl;
        }
        
    } catch (const invalid_argument& e) {
        cout << "ERROR: " << e.what() << endl;
    }
}

void verReservasDePelicula() {
    mostrarEncabezado("V E R  R E S E R V A S  D E  P E L Í C U L A");

    // 1. Listar películas disponibles
    list<DtPelicula> peliculas = iVerReservasDePelicula->listarPeliculas();
    if (peliculas.empty()) {
        cout << "No hay películas registradas en el sistema." << endl;
        return;
    }

    cout << "PELÍCULAS DISPONIBLES:" << endl;
    for (list<DtPelicula>::iterator it = peliculas.begin(); it != peliculas.end(); ++it) {
        cout << "- " << it->getTitulo() << endl;
    }

    // 2. Seleccionar película
    string titulo;
    cout << endl << "Ingrese el título de la película: ";
    cin.ignore();
    getline(cin, titulo);

    // 3. Obtener las funciones de esa película
    list<DtFuncion> funciones = iVerReservasDePelicula->obtenerFuncionesDePelicula(titulo);
    if (funciones.empty()) {
        cout << "No hay funciones registradas para esta película." << endl;
        return;
    }

    cout << endl << "========================================" << endl;
    cout << "RESERVAS PARA LA PELÍCULA: " << titulo << endl;
    cout << "========================================" << endl;

    // 4. Iterar por cada función y mostrar sus reservas
    for (list<DtFuncion>::iterator itFun = funciones.begin(); itFun != funciones.end(); ++itFun) {
        cout << endl << "--- Función ID: " << itFun->getIdFun()
             << " | Fecha: " << itFun->getDiaFun().getDia() << "/" << itFun->getDiaFun().getMes() << "/" << itFun->getDiaFun().getAnio()
             << " | Hora: " << itFun->getHoraFun().getHoraIni() << " ---" << endl;
        
        list<DtReserva> reservas = iVerReservasDePelicula->obtenerReservasDeFuncion(itFun->getIdFun());
        
        if (reservas.empty()) {
            cout << "No hay reservas para esta función." << endl;
        } else {
            for (list<DtReserva>::iterator itRes = reservas.begin(); itRes != reservas.end(); ++itRes) {
                cout << "  ID Reserva: " << itRes->getId() << endl;
                cout << "  Cantidad de entradas: " << itRes->getCantEntradas() << endl;
                cout << "  Costo total: $" << itRes->getCosto() << endl;
                cout << "  Forma de pago: " << itRes->getFormaPago() << endl;
                cout << "  ------------------------" << endl;
            }
        }
    }
}

void verInformacionPelicula() {
    mostrarEncabezado("V E R  I N F O R M A C I Ó N  D E  P E L Í C U L A");
    
    // 1. Listar películas disponibles
    list<DtPelicula> peliculas = iVerInformacionPelicula->listarPeliculas();
    
    if (peliculas.empty()) {
        cout << "No hay películas registradas en el sistema." << endl;
        return;
    }
    
    cout << "PELÍCULAS DISPONIBLES:" << endl;
    for (list<DtPelicula>::iterator it = peliculas.begin(); it != peliculas.end(); ++it) {
        cout << "- " << it->getTitulo() << endl;
    }
    
    cout << endl << "¿Qué desea hacer?" << endl;
    cout << "1. Ver información de una película" << endl;
    cout << "2. Salir" << endl;
    cout << "Seleccione una opción (1-2): ";
    
    int opcion;
    cin >> opcion;
    
    if (opcion == 2) {
        cout << "Saliendo..." << endl;
        return;
    } else if (opcion != 1) {
        cout << "Opción inválida." << endl;
        return;
    }
    
    // 2. Seleccionar película por nombre
    string tituloSeleccionado;
    cout << endl << "Ingrese el título de la película: ";
    cin.ignore();
    getline(cin, tituloSeleccionado);
    
    // 4. Mostrar información de la película
    try {
        DtPelicula pelicula = iVerInformacionPelicula->obtenerInformacionPelicula(tituloSeleccionado);
        cout << endl << "=========================" << endl;
        cout << "INFORMACIÓN DE LA PELÍCULA" << endl;
        cout << "=========================" << endl;
        cout << "Título: " << pelicula.getTitulo() << endl;
        cout << "Poster: " << pelicula.getPoster() << endl;
        cout << "Puntaje Promedio: " << pelicula.getPuntajePromedio() << "/5" << endl;
        cout << endl << "Sinopsis:" << endl;
        cout << pelicula.getSinopsis() << endl;
        cout << "=========================" << endl;
        
        // 5. Preguntar si quiere ver información adicional de cines
        char respuesta;
        cout << endl << "¿Desea ver información adicional de los cines donde se proyecta? (s/n): ";
        cin >> respuesta;
        
        if (respuesta == 's' || respuesta == 'S') {
            // 6. Mostrar información de cines
            list<DtCine> cines = iVerInformacionPelicula->obtenerCinesPelicula(tituloSeleccionado);
            
            cout << endl << "=============================" << endl;
            cout << "INFORMACIÓN ADICIONAL DE CINES" << endl;
            cout << "=============================" << endl;
            
            if (cines.empty()) {
                cout << "Esta película no se proyecta en ningún cine actualmente." << endl;
            } else {
                cout << "La película '" << tituloSeleccionado << "' se proyecta en los siguientes cines:" << endl;
                int contadorCines = 1;
                for (list<DtCine>::iterator it = cines.begin(); it != cines.end(); ++it) {
                    cout << endl << "Cine " << contadorCines << ":" << endl;
                    cout << "  ID: " << it->getId() << endl;
                    cout << "  Dirección: " << it->getDireccion().getCalle() << " " << it->getDireccion().getNumero() << endl;
                    contadorCines++;
                }
                
                // 7. Preguntar si quiere ver funciones de un cine específico
                cout << endl << "¿Desea seleccionar un cine para ver las funciones de la película? (s/n): ";
                cin >> respuesta;
                
                if (respuesta == 's' || respuesta == 'S') {
                    int idCine;
                    cout << "Ingrese el ID del cine: ";
                    cin >> idCine;
                    
                    // 8. Mostrar funciones en el cine seleccionado
                    list<DtFuncion> funciones = iVerInformacionPelicula->obtenerFuncionesPeliculaEnCine(tituloSeleccionado, idCine);
                    
                    cout << endl << "FUNCIONES DE LA PELÍCULA EN EL CINE SELECCIONADO:" << endl;
                    if (funciones.empty()) {
                        cout << "No hay funciones de esta película en el cine seleccionado." << endl;
                    } else {
                        for (list<DtFuncion>::iterator it = funciones.begin(); it != funciones.end(); ++it) {
                            cout << "  Función ID: " << it->getIdFun()
                                 << " | Fecha: " << it->getDiaFun().getDia() << "/" << it->getDiaFun().getMes() << "/" << it->getDiaFun().getAnio()
                                 << " | Hora: " << it->getHoraFun().getHoraIni() << endl;
                        }
                    }
                }
            }
            cout << "=============================" << endl;
        }
        
    } catch (const invalid_argument& e) {
        cout << "ERROR: " << e.what() << endl;
    }
}

void modificarFechaSistema() {
    mostrarEncabezado("M O D I F I C A R  F E C H A  D E L  S I S T E M A");

    string fechaHora;
    cout << "Ingrese la nueva fecha y hora (formato dd/mm/aaaa hh:mm): ";
    cin.ignore();
    getline(cin, fechaHora);

    try {
        iReloj->modificarFecha(fechaHora);
        cout << "Fecha del sistema modificada correctamente." << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
}

void consultarFechaSistema() {
    mostrarEncabezado("C O N S U L T A R  F E C H A  D E L  S I S T E M A");

    try {
        string fechaHora = iReloj->consultarFecha();
        cout << "La fecha actual del sistema es: " << fechaHora << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
}

void menuReloj() {
    int opc;
    do {
        mostrarEncabezado("R E L O J  D E L  S I S T E M A");
        cout << "1. Modificar fecha del sistema" << endl;
        cout << "2. Consultar fecha del sistema" << endl;
        cout << "3. Volver" << endl;
        cout << "Opción: ";
        cin >> opc;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            opc = -1;
        }

        switch (opc) {
            case 1:
                modificarFechaSistema();
                break;
            case 2:
                consultarFechaSistema();
                break;
            case 3:
                break;
            default:
                cout << "Opción incorrecta" << endl;
        }

        if (opc != 3) {
            cout << endl << "Presione Enter para continuar...";
            cin.ignore(1000, '\n');
            cin.get();
        }

    } while (opc != 3);
}

void verComentariosPuntajesPelicula() {
    mostrarEncabezado("V E R  C O M E N T A R I O S  Y  P U N T A J E S");
    
    set<DtPelicula*> peliculas = iVerComentariosyPuntajesdePelicula->listarPeliculas();
    if (peliculas.empty()) {
        cout << "No hay películas registradas en el sistema." << endl;
        return;
    }
    
    cout << "PELÍCULAS DISPONIBLES:" << endl;
    for (set<DtPelicula*>::iterator it = peliculas.begin(); it != peliculas.end(); ++it) {
        cout << "- " << (*it)->getTitulo() << endl;
    }
    
    string titulo;
    cout << endl << "Ingrese el título de la película: ";
    cin.ignore();
    getline(cin, titulo);
    
    try {
        DtPeliFull* peliculaCompleta = iVerComentariosyPuntajesdePelicula->selectPeli(titulo);
        
        cout << endl << titulo << endl;
        cout << "Puntaje promedio: " << peliculaCompleta->getPuntajePromedio() << " (" << peliculaCompleta->getCantPuntuaciones() << " usuarios)" << endl;
        
        // Mostrar comentarios
        cout << endl << "Comentarios" << endl;
        list<DtComentario*> comentarios = peliculaCompleta->getComentarios();
        if (comentarios.empty()) {
            cout << "No hay comentarios para esta película." << endl;
        } else {
            int comentarioId = 1;
            for (list<DtComentario*>::iterator it = comentarios.begin(); it != comentarios.end(); ++it) {
                cout << "[ID: " << comentarioId << "] " << (*it)->getNickname() << ": " << (*it)->getTexto() << endl;
                
                // Mostrar respuestas con indentación
                set<DtComentario*> respuestas = (*it)->getRespuestas();
                for (set<DtComentario*>::iterator itResp = respuestas.begin(); itResp != respuestas.end(); ++itResp) {
                    cout << "  " << (*itResp)->getNickname() << ": " << (*itResp)->getTexto() << endl;
                }
                comentarioId++;
            }
        }
        
        // Mostrar puntajes individuales
        cout << endl << "Puntajes" << endl;
        set<DtPuntaje*> puntajes = peliculaCompleta->getPuntajes();
        if (puntajes.empty()) {
            cout << "No hay puntajes para esta película." << endl;
        } else {
            for (set<DtPuntaje*>::iterator it = puntajes.begin(); it != puntajes.end(); ++it) {
                cout << (*it)->getNickUsuario() << ": " << (*it)->getValor() << endl;
            }
        }
        
    } catch (const invalid_argument& e) {
        cout << "ERROR: " << e.what() << endl;
    }
    
}



void menu(){
    mostrarEncabezado("M E N U  C I N E M A");
    cout <<"1. Iniciar Sesion"<<endl;
    cout <<"2. Cerrar Sesion"<<endl;
    cout <<"3. Alta Usuario"<<endl;
    cout <<"4. Alta Pelicula"<<endl;
    cout <<"5. Alta Cine"<<endl;
    cout <<"6. Alta Funcion"<<endl;
    cout <<"7. Crear Reserva"<<endl;
    cout <<"8. Ver Reservas de Pelicula"<<endl;
    cout <<"9. Eliminar Pelicula"<<endl;
    cout <<"10. Puntuar Pelicula"<<endl;
    cout <<"11. Comentar Pelicula"<<endl;
    cout <<"12. Ver Información de Película"<<endl;
    cout <<"13. Ver Comentarios y Puntajes de Película"<<endl;
    cout <<"14. Reloj del Sistema"<<endl;
    cout <<"15. Salir " <<endl;
    cout <<"_" <<endl;
    cout << "OPCION: ";
}

int main() {
    fabrica = Fabrica::getInstancia();
    iAltaUsuario = fabrica->getICAltaUsuario();
    iIniciarSesion = fabrica->getICIniciarSesion();
    iCerrarSesion = fabrica->getICCerrarSesion();
    iAltaPelicula = fabrica->getICAltaPelicula();
    iAltaCine = fabrica->getICAltaCine();
    iAltaFuncion = fabrica->getICAltaFuncion();
    iPuntuarPelicula = fabrica->getICPuntuarPelicula();
    iCrearReserva = fabrica->getICCrearReserva();
    iComentarPelicula = fabrica->getICComentarPelicula();
    iEliminarPelicula = fabrica->getICEliminarPelicula();
    iVerReservasDePelicula = fabrica->getICVerReservasDePelicula();
    iVerInformacionPelicula = fabrica->getICVerInformacionPelicula();
    iReloj = fabrica->getICReloj();
    iVerComentariosyPuntajesdePelicula = fabrica->getICVerComentariosyPuntajesdePelicula();

    int opcion;
    do {
        menu();
        cin >> opcion;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            opcion = -1; 
        }

        switch(opcion){
            case 1: iniciarSesion();
                break;
            case 2: cerrarSesion();
                break;
            case 3: altaUsuario();
                break;
            case 4: altaPelicula();
                break;
            case 5: altaCine();
                break;
            case 6: altaFuncion();
                break;
            case 7: crearReserva();
                break;
            case 8: verReservasDePelicula();
                break;
            case 9: eliminarPelicula();
                break;
            case 10: puntuarPelicula();
                break;
            case 11: comentarPelicula();
                break;
            case 12: verInformacionPelicula();
                break;
            case 13: verComentariosPuntajesPelicula();
                break;
            case 14: menuReloj();
                break;
            case 15:
                break;
            default:
                cout << "OPCIÓN INCORRECTA" << endl;
        }

        if (opcion != 15) {
            cout << endl << "Presione Enter para continuar...";
            cin.ignore(1000, '\n');
            cin.get();
        }

    } while (opcion != 15);
    
    cout << "SALIENDO..." << endl;
    return 0;
}