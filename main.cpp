#include <iostream>
#include "Fabrica.h"
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
#include "ManejadorCine.h"
#include "ICVerReservasDePelicula.h"
#include "ICVerInformacionPelicula.h"
#include "ManejadorPelicula.h"
using namespace std;

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

void altaUsuario(){
    system("clear");
    cout <<"_" <<endl;
    cout <<"_A L T A  D E  U S U A R I O_"<< endl;
    
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
    cout << endl << "USUARIO REGISTRADO CORRECTAMENTE" << endl;
}

void iniciarSesion() {
    system("clear");
    cout <<"_" <<endl;
    cout <<"_I N I C I A R  S E S I O N_"<< endl;
    
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
            
            if (opcion == 2) {
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
    system("clear");
    cout <<"_" <<endl;
    cout <<"_C E R R A R  S E S I O N_"<< endl;
    
    if(iCerrarSesion->cerrarSesion()) {
        cout << endl << "SESION CERRADA CORRECTAMENTE" << endl;
    } else {
        cout << endl << "ERROR: NO HAY SESION INICIADA" << endl;
    }
}

void altaPelicula() {
    system("clear");
    cout <<"_" <<endl;
    cout <<"_A L T A  D E  P E L I C U L A_"<< endl;
    
    if (!iAltaPelicula->hayUsuarioLogueado()) {
        cout << "ERROR: Debe iniciar sesión para dar de alta una película." << endl;
        return;
    }
    
    string titulo, sinopsis, url;
    int opcion;
    ManejadorPelicula* mp = ManejadorPelicula::getInstancia();
    while (true) {
        cout << "TITULO: ";
        cin.ignore();
        getline(cin, titulo);
        if (mp->buscarPelicula(titulo) != nullptr) {
            cout << "ERROR: Ya existe una película con ese título." << endl;
            cout << "1. Reintentar" << endl;
            cout << "2. Cancelar" << endl;
            cout << "Opción: ";
            cin >> opcion;
            if (opcion == 2) {
                cout << "Operación cancelada." << endl;
                return;
            }
            cin.ignore(); // Limpiar buffer antes de volver a pedir título
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
    system("clear");
    cout <<"_" <<endl;
    cout <<"_A L T A  D E  C I N E_"<< endl;
    
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
    system("clear");
    cout << "_" << endl;
    cout << "_A L T A  D E  F U N C I O N_" << endl;

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
        iAltaFuncion->mostrarSalasConOcupacion();

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
        cin.ignore(10000, '\n');
        system("clear");
        
    } while (tolower(continuar) == 's');
}

void comentarPelicula() {
    system("clear");
    cout << "_" << endl;
    cout << "_C O M E N T A R  P E L I C U L A_" << endl;

    // Verificar si hay usuario logueado
    if (!iComentarPelicula->hayUsuarioLogueado()) {
        cout << "ERROR: Debe iniciar sesión para comentar películas" << endl;
        return;
    }

    try {
        // Listar películas
        cout << "PELÍCULAS DISPONIBLES:" << endl;
        iComentarPelicula->listarPeliculas();

        // Seleccionar película
        string titulo;
        cout << endl << "Ingrese el título de la película: ";
        cin.ignore(10000, '\n');
        getline(cin, titulo);
        iComentarPelicula->selectPeli(titulo);

        char continuar;
        do {
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
            cin.ignore(10000, '\n');
            system("clear");

        } while (tolower(continuar) == 's');

    } catch (const invalid_argument& e) {
        cout << "ERROR: " << e.what() << endl;
    }
}

void puntuarPelicula() {
    system("clear");
    cout << "_" << endl;
    cout << "_P U N T U A R  P E L I C U L A_" << endl;

    string titulo;
    int puntaje;

    cout << "TITULO DE LA PELICULA: ";
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
    system("clear");
    cout << "_" << endl;
    cout << "_C R E A R  R E S E R V A_" << endl;

    // Verificar si hay usuario logueado
    if (!iCrearReserva->hayUsuarioLogueado()) {
        cout << "ERROR: Debe iniciar sesión para crear una reserva" << endl;
        return;
    }

    // Listar películas disponibles
    list<DtPelicula> peliculas = iCrearReserva->listarPeliculas();
    if (peliculas.empty()) {
        cout << "No hay películas disponibles para reservar." << endl;
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
    iCrearReserva->selectPelicula(titulo);

    // Listar funciones disponibles
    list<DtFuncion> funciones = iCrearReserva->listarFunciones();
    if (funciones.empty()) {
        cout << "No hay funciones disponibles para esta película." << endl;
        return;
    }

    cout << endl << "FUNCIONES DISPONIBLES:" << endl;
    for (list<DtFuncion>::iterator it = funciones.begin(); it != funciones.end(); ++it) {
        cout << "ID: " << it->getIdFun() << " - Fecha: " << it->getDiaFun().getDia() << "/" 
             << it->getDiaFun().getMes() << "/" << it->getDiaFun().getAnio() 
             << " - Hora: " << it->getHoraFun().getHoraIni() << endl;
    }

    // Seleccionar función
    int idFuncion;
    cout << endl << "Ingrese el ID de la función: ";
    cin >> idFuncion;
    iCrearReserva->selectFuncion(idFuncion);

    // Ingresar cantidad de entradas
    int cantEntradas;
    cout << endl << "Cantidad de entradas: ";
    cin >> cantEntradas;
    iCrearReserva->ingresarCantidadEntradas(cantEntradas);

    // Seleccionar forma de pago
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
        float descuento;
        cout << "Ingrese la financiera: ";
        cin.ignore();
        getline(cin, financiera);
        cout << "Ingrese el porcentaje de descuento: ";
        cin >> descuento;
        iCrearReserva->seleccionarCredito(financiera, descuento);
    }

    // Confirmar reserva
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
}

void eliminarPelicula() {
    system("clear");
    cout << "_" << endl;
    cout << "_E L I M I N A R  P E L I C U L A_" << endl;

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

    // Intentar eliminar la película
    if (iEliminarPelicula->eliminarPelicula(titulo)) {
        cout << endl << "La película fue eliminada exitosamente." << endl;
    }
}

void verReservasDePelicula() {
    system("clear");
    cout << "_" << endl;
    cout << "_V E R  R E S E R V A S  D E  P E L I C U L A_" << endl;

    // Listar películas disponibles
    list<DtPelicula> peliculas = iVerReservasDePelicula->listarPeliculas();
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

    // Listar reservas de la película
    list<DtReserva> reservas = iVerReservasDePelicula->listarReservasDePelicula(titulo);
    if (reservas.empty()) {
        cout << "No hay reservas para esta película." << endl;
        return;
    }

    cout << endl << "RESERVAS DE LA PELÍCULA " << titulo << ":" << endl;
    for (list<DtReserva>::iterator it = reservas.begin(); it != reservas.end(); ++it) {
        cout << "ID Reserva: " << it->getId() << endl;
        cout << "Cantidad de entradas: " << it->getCantEntradas() << endl;
        cout << "Costo total: $" << it->getCosto() << endl;
        cout << "Forma de pago: " << it->getFormaPago() << endl;
        cout << "------------------------" << endl;
    }
}

void verInformacionPelicula() {
    system("clear");
    iVerInformacionPelicula->ejecutar();
}

void menu();

int main() {
    // Obtener la instancia de la Fabrica
    fabrica = Fabrica::getInstancia();
    
    // Obtener las interfaces a través de la Fabrica
    iIniciarSesion = fabrica->getICIniciarSesion();
    iCerrarSesion = fabrica->getICCerrarSesion();
    iAltaUsuario = fabrica->getICAltaUsuario();
    iAltaPelicula = fabrica->getICAltaPelicula();
    iAltaCine = fabrica->getICAltaCine();
    iAltaFuncion = fabrica->getICAltaFuncion();
    iPuntuarPelicula = fabrica->getICPuntuarPelicula();
    iComentarPelicula = fabrica->getICComentarPelicula();
    iCrearReserva = fabrica->getICCrearReserva();
    iEliminarPelicula = fabrica->getICEliminarPelicula();
    iVerReservasDePelicula = fabrica->getICVerReservasDePelicula();
    iVerInformacionPelicula = fabrica->getICVerInformacionPelicula();
    
    int opcion;
    menu();
    cin >> opcion;
    while(opcion != 13){
        system("clear");
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
            case 13: cout << "SALIENDO..." << endl;
                break;
            default:
                cout << "OPCIÓN INCORRECTA" << endl;
        }
        system("sleep 5");
        system("clear");
        menu();
        cin >> opcion;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            opcion = -1;
        }
    }
    
    cout << "SALIENDO..." << endl;
    return 0;
}

void menu(){
    system("clear");
    cout <<"_" <<endl;
    cout <<"M E N U  C I N E MA"<< endl;
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
    cout <<"13. Salir " <<endl;
    cout <<"_" <<endl;
    cout << "OPCION: ";
}