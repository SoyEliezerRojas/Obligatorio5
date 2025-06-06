#include <iostream>
#include "Fabrica.h"
#include "ICIniciarSesion.h"
#include "ICCerrarSesion.h"
#include "ICAltaUsuario.h"
#include "ICAltaPelicula.h"
#include "ICAltaCine.h"
#include "DtDireccion.h"
#include "ManejadorCine.h"
using namespace std;

Fabrica* fabrica;
ICAltaUsuario* iAltaUsuario;
ICIniciarSesion* iIniciarSesion;
ICCerrarSesion* iCerrarSesion;
ICAltaPelicula* iAltaPelicula;
ICAltaCine* iAltaCine;

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
    
    int opcion;
    menu();
    cin>> opcion;
    while(opcion != 10){
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
			case 6: //altaFuncion();
				break;
            case 7: //crearReserva();
                break;
            case 8: //verReservasPelicula();
                break;
            case 9: //eliminarPelicula();
                break;
            case 10: system("exit");
				cout << "SALIENDO..." << endl;
				break;
			default:
				cout << "OPCIÓN INCORRECTA" << endl;
		}
		system("sleep 5");
        system("clear");
		menu();
		cin >> opcion;
    }
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
        cout <<"10. Salir " <<endl;
		cout <<"_" <<endl;
		cout << "OPCION: ";
}