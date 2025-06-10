#include <iostream>
#include <limits>
#include "Fabrica.h"
#include "ICIniciarSesion.h"
#include "ICCerrarSesion.h"
#include "ICAltaUsuario.h"
#include "ICAltaPelicula.h"
#include "ICAltaCine.h"
#include "ICAltaFuncion.h"
#include "ICPuntuarPelicula.h"
#include "ICComentarPelicula.h"
#include "DtDireccion.h"
#include "DtPelicula.h"
#include "DtCine.h"
#include "DtSala.h"
#include "DtFuncion.h"
#include "DtFecha.h"
#include "DtHorario.h"
#include "DtComentario.h"
using namespace std;

Fabrica* fabrica;
ICAltaUsuario* iAltaUsuario;
ICIniciarSesion* iIniciarSesion;
ICCerrarSesion* iCerrarSesion;
ICAltaPelicula* iAltaPelicula;
ICAltaCine* iAltaCine;
ICAltaFuncion* iAltaFuncion;
ICPuntuarPelicula* iPuntuarPelicula;
ICComentarPelicula* iComentarPelicula;

void altaUsuario(){
    system("clear");
	cout <<"_" <<endl;
	cout <<"_A L T A  D E  U S U A R I O_"<< endl;
    string nickname, contrasenia, url;
    int aux;
    cout << "NICKNAME: ";
	cin >> nickname;
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
}

void iniciarSesion() {
    system("clear");
    cout <<"_" <<endl;
    cout <<"_I N I C I A R  S E S I O N_"<< endl;
    string nickname, contrasenia;
    cout << "NICKNAME: ";
    cin >> nickname;
    cout << endl << "PASSWORD: ";
    cin >> contrasenia;
    
    if(iIniciarSesion->iniciarSesion(nickname, contrasenia)) {
        cout << endl << "SESION INICIADA CORRECTAMENTE" << endl;
    } else {
        cout << endl << "ERROR AL INICIAR SESION" << endl;
    }
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
    string titulo, sinopsis, url;
    
    cout << "TITULO: ";
    cin.ignore(); // Clear the buffer
    getline(cin, titulo);
    
    cout << endl << "SINOPSIS: ";
    getline(cin, sinopsis);
    
    cout << endl << "URL DEL POSTER: ";
    getline(cin, url);
    
    if(iAltaPelicula->altaPelicula(titulo, sinopsis, url)) {
        cout << endl << "PELICULA REGISTRADA CORRECTAMENTE" << endl;
    } else {
        cout << endl << "ERROR: YA EXISTE UNA PELICULA CON ESE TITULO" << endl;
    }
}

void altaCine() {
    system("clear");
    cout <<"_" <<endl;
    cout <<"_A L T A  D E  C I N E_"<< endl;
    
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
    
    // Dar de alta el cine
    iAltaCine->altaCine();
    cout << endl << "CINE " << nextId << " REGISTRADO CORRECTAMENTE" << endl;
    cout << "Direccion: " << calle << " " << numero << endl;
    cout << "Cantidad de salas: " << cantSalas << endl;
}

void altaFuncion() {
    system("clear");
    cout << "_" << endl;
    cout << "_A L T A  D E  F U N C I O N_" << endl;

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
    cin.ignore(10000, '\n');
    getline(cin, titulo);
    if(titulo.empty()) {
        cout << "ERROR: El título no puede estar vacío" << endl;
        return;
    }
    
    try {
        iAltaFuncion->selectPeli(titulo);
    } catch (const invalid_argument& e) {
        cout << "ERROR: " << e.what() << endl;
        return;
    }

    // Listar cines disponibles
    list<DtCine> cines = iAltaFuncion->listarCines();
    if (cines.empty()) {
        cout << "ERROR: No hay cines registrados en el sistema." << endl;
        return;
    }

    cout << endl << "CINES DISPONIBLES:" << endl;
    for (list<DtCine>::iterator it = cines.begin(); it != cines.end(); ++it) {
        cout << "ID: " << it->getId() << " - Dirección: " << it->getDireccion().getCalle() 
             << " " << it->getDireccion().getNumero() << endl;
    }

    // Seleccionar cine
    string idCine;
    cout << endl << "Ingrese el ID del cine: ";
    cin >> idCine;
    if(cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "ERROR: ID de cine inválido" << endl;
        return;
    }

    try {
        iAltaFuncion->selectCine(idCine);
    } catch (const invalid_argument& e) {
        cout << "ERROR: " << e.what() << endl;
        return;
    }

    // Listar salas del cine
    list<DtSala> salas = iAltaFuncion->listarSalas();
    if (salas.empty()) {
        cout << "ERROR: No hay salas disponibles en este cine." << endl;
        return;
    }

    cout << endl << "SALAS DISPONIBLES:" << endl;
    for (list<DtSala>::iterator it = salas.begin(); it != salas.end(); ++it) {
        cout << "ID: " << it->getId() << " - Capacidad: " << it->getCapacidad() << endl;
    }

    // Seleccionar sala
    int idSala;
    cout << endl << "Ingrese el ID de la sala: ";
    cin >> idSala;
    if(cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "ERROR: ID de sala inválido" << endl;
        return;
    }

    try {
        iAltaFuncion->selectSala(idSala);
    } catch (const invalid_argument& e) {
        cout << "ERROR: " << e.what() << endl;
        return;
    }

    // Ingresar datos de la función
    int idFuncion, hora, minutos, dia, mes, anio;
    
    cout << endl << "DATOS DE LA FUNCIÓN" << endl;
    cout << "ID: ";
    cin >> idFuncion;
    if(cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "ERROR: ID de función inválido" << endl;
        return;
    }

    cout << "Hora (HH MM): ";
    cin >> hora >> minutos;
    if(cin.fail() || hora < 0 || hora > 23 || minutos < 0 || minutos > 59) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "ERROR: Hora inválida" << endl;
        return;
    }

    string horaInicio = (hora < 10 ? "0" : "") + to_string(hora) + ":" + 
                       (minutos < 10 ? "0" : "") + to_string(minutos);

    cout << "Fecha (DD MM AAAA): ";
    cin >> dia >> mes >> anio;
    if(cin.fail() || dia < 1 || dia > 31 || mes < 1 || mes > 12) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "ERROR: Fecha inválida" << endl;
        return;
    }

    try {
        DtFecha fecha(dia, mes, anio);
        iAltaFuncion->altaFuncion(idFuncion, horaInicio, fecha);
        cout << endl << "FUNCIÓN CREADA EXITOSAMENTE" << endl;
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
    
    int opcion;
    menu();
    cin >> opcion;
    while(opcion != 12){
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
            case 7: //crearReserva();
                break;
            case 8: //verReservasPelicula();
                break;
            case 9: //eliminarPelicula();
                break;
            case 10: puntuarPelicula();
                break;
            case 11: comentarPelicula();
                break;
            case 12: cout << "SALIENDO..." << endl;
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
    //system("clear");
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
    cout <<"12. Salir " <<endl;
    cout <<"_" <<endl;
    cout << "OPCION: ";
}