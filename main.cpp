#include <iostream>
#include "Fabrica.h"
#include "ICIniciarSesion.h"
#include "ICCerrarSesion.h"
using namespace std;

int main() {
    // Obtener la instancia de la Fabrica
    Fabrica* fabrica = Fabrica::getInstancia();
    
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
    
    return 0;
}