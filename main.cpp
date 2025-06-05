#include <iostream>
#include "Fabrica.h"
#include "ICIniciarSesion.h"
#include "ICCerrarSesion.h"
#include "ICAltaUsuario.h"
using namespace std;

Fabrica* fabrica;
ICAltaUsuario* iAltaUsuario;
ICIniciarSesion* iIniciarSesion;
ICCerrarSesion* iCerrarSesion;

void altaUsuario(){
    system("clear");
	cout <<"_" <<endl;
	cout <<"_A L T AD E_ U S U A R I O_"<< endl;
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

void menu();

int main() {
    // Obtener la instancia de la Fabrica
    fabrica = Fabrica::getInstancia();
    
    // Obtener las interfaces a través de la Fabrica
    iIniciarSesion = fabrica->getICIniciarSesion();
    iCerrarSesion = fabrica->getICCerrarSesion();
    iAltaUsuario = fabrica->getICAltaUsuario();
    int opcion;
    menu();
    cin>> opcion;
    while(opcion != 10){
		switch(opcion){
			case 1: //iniciarSesion();
				break;
			case 2: //cerrarSesion();
				break;
			case 3: altaUsuario();
				break;
			case 4: //altaPelicula();
				break;
			case 5: //altaCine();
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
			default:
				cout << "OPCIÓN INCORRECTA" << endl;
		}
		system("sleep 5");
        system("clear");
		menu();
		cin >> opcion;
    }

    
    // Obtener las interfaces a través de la Fabrica
    ICIniciarSesion* iIniciarSesion = fabrica->getICIniciarSesion();
    ICCerrarSesion* iCerrarSesion = fabrica->getICCerrarSesion();
    
    

    // Intentar iniciar sesión
    string nick = "nick";
    string pass = "password123";
    if (iIniciarSesion->iniciarSesion(nick, pass)) {
        cout << "Sesión iniciada correctamente" << endl;
        
        // Cerrar sesión
        iCerrarSesion->cerrarSesion();
        cout << "Sesión cerrada" << endl;
    } else {
        cout << "Error al iniciar sesión" << endl;
    }


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