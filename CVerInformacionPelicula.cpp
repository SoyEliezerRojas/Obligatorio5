#include "CVerInformacionPelicula.h"
#include "Funcion.h"
#include "DtHorario.h"
#include "DtFecha.h"

CVerInformacionPelicula::CVerInformacionPelicula() {
    this->manejadorPelicula = ManejadorPelicula::getInstancia();
    this->manejadorCine = ManejadorCine::getInstancia();
}

void CVerInformacionPelicula::ejecutar() {
    int opcion;
    bool continuar = true;
    
    while (continuar) {
        cout << "\n=== VER INFORMACION DE PELICULA ===" << endl;
        cout << "Peliculas disponibles:" << endl;
        
        // Mostrar lista de películas
        mostrarListaPeliculas();
        
        // Obtener lista de películas para validar selección
        list<DtPelicula> peliculas = manejadorPelicula->listarPeliculas();
        int numPeliculas = peliculas.size();
        
        if (numPeliculas == 0) {
            cout << "\nNo hay peliculas registradas en el sistema." << endl;
            return;
        }
        
        cout << "\n" << (numPeliculas + 1) << ". Salir" << endl;
        cout << "\nSeleccione una pelicula (1-" << (numPeliculas + 1) << "): ";
        cin >> opcion;
        
        // Validar opción
        if (!validarOpcionMenu(opcion, numPeliculas + 1)) {
            cout << "\nOpcion invalida. Intente nuevamente." << endl;
            continue;
        }
        
        // Si eligió salir
        if (opcion == numPeliculas + 1) {
            continuar = false;
            cout << "\nSaliendo del sistema de informacion de peliculas..." << endl;
            continue;
        }
        
        // Obtener título de la película seleccionada
        string tituloSeleccionado = obtenerTituloPorIndice(opcion - 1);
        
        if (tituloSeleccionado.empty()) {
            cout << "\nError al obtener la pelicula seleccionada." << endl;
            continue;
        }
        
        // Mostrar información de la película
        mostrarInformacionPelicula(tituloSeleccionado);
        
        // Preguntar si quiere ver información adicional de los cines
        char respuesta;
        cout << "\n¿Desea ver informacion adicional de los cines donde se proyecta? (s/n): ";
        cin >> respuesta;
        
        if (respuesta == 's' || respuesta == 'S') {
            mostrarInformacionCines(tituloSeleccionado);
        }
        
        // Preguntar si quiere continuar
        cout << "\n¿Desea ver informacion de otra pelicula? (s/n): ";
        cin >> respuesta;
        
        if (respuesta != 's' && respuesta != 'S') {
            continuar = false;
            cout << "\nGracias por usar el sistema de informacion de peliculas." << endl;
        }
    }
}

void CVerInformacionPelicula::mostrarListaPeliculas() {
    list<DtPelicula> peliculas = manejadorPelicula->listarPeliculas();
    
    if (peliculas.empty()) {
        cout << "No hay peliculas disponibles." << endl;
        return;
    }
    
    int contador = 1;
    for (DtPelicula pelicula : peliculas) {
        cout << contador << ". " << pelicula.getTitulo() << endl;
        contador++;
    }
}

void CVerInformacionPelicula::mostrarInformacionPelicula(const string& titulo) {
    Pelicula* pelicula = manejadorPelicula->buscarPelicula(titulo);
    
    if (pelicula == nullptr) {
        cout << "\nError: No se encontro la pelicula seleccionada." << endl;
        return;
    }
    
    cout << "\n=========================" << endl;
    cout << "INFORMACION DE LA PELICULA" << endl;
    cout << "=========================" << endl;
    cout << "Titulo: " << pelicula->getTitulo() << endl;
    cout << "Poster: " << pelicula->getPoster() << endl;
    cout << "Puntaje Promedio: " << pelicula->getPuntajeProm() << "/5" << endl;
    cout << "\nSinopsis:" << endl;
    cout << pelicula->getSinopsis() << endl;
    cout << "=========================" << endl;
}

void CVerInformacionPelicula::mostrarInformacionCines(const string& titulo) {
    Pelicula* pelicula = manejadorPelicula->buscarPelicula(titulo);
    if (pelicula == nullptr) {
        cout << "\nError: No se encontro la pelicula seleccionada." << endl;
        return;
    }
    list<Cine*> cines = pelicula->getCines();
    cout << "\n=============================" << endl;
    cout << "INFORMACION ADICIONAL DE CINES" << endl;
    cout << "=============================" << endl;
    if (cines.empty()) {
        cout << "Esta pelicula no se proyecta en ningun cine actualmente." << endl;
    } else {
        cout << "La pelicula '" << titulo << "' se proyecta en los siguientes cines:" << endl;
        int contador = 1;
        for (Cine* cine : cines) {
            cout << "\nCine " << contador << ":" << endl;
            cout << "  ID: " << cine->getIdCine() << endl;
            DtDireccion direccion = cine->getDirecCine();
            cout << "  Direccion: " << direccion.getCalle() << " " << direccion.getNumero() << endl;
            list<Sala*> salas = cine->getSalas();
            cout << "  Numero de salas: " << salas.size() << endl;
            contador++;
        }
        cout << "=============================" << endl;
        
        // Permitir seleccionar un cine para ver funciones
        char respuesta;
        cout << "\n¿Desea seleccionar un cine para ver las funciones de la pelicula? (s/n): ";
        cin >> respuesta;
        if (respuesta == 's' || respuesta == 'S') {
            int idCine;
            cout << "Ingrese el ID del cine: ";
            cin >> idCine;
            mostrarFuncionesEnCine(titulo, idCine);
        }
    }
    cout << "=============================" << endl;
}

void CVerInformacionPelicula::mostrarFuncionesEnCine(const string& titulo, int idCine) {
    Cine* cine = manejadorCine->buscarCine(idCine);
    if (!cine) {
        cout << "Cine no encontrado." << endl;
        return;
    }
    list<Sala*> salas = cine->getSalas();
    bool hayFunciones = false;
    cout << "\nFUNCIONES DE LA PELICULA EN EL CINE SELECCIONADO:" << endl;
    for (Sala* sala : salas) {
        list<Funcion*> funciones = sala->getFunciones();
        for (Funcion* funcion : funciones) {
            if (funcion->getPelicula() && funcion->getPelicula()->getTitulo() == titulo) {
                DtFecha fecha = funcion->getDiaFun();
                DtHorario horario = funcion->getHoraFun();
                cout << "  Sala ID: " << sala->getId() << " | Funcion ID: " << funcion->getIdFun()
                     << " | Fecha: " << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio()
                     << " | Hora: " << horario.getHoraIni() << endl;
                hayFunciones = true;
            }
        }
    }
    if (!hayFunciones) {
        cout << "No hay funciones de esta pelicula en el cine seleccionado." << endl;
    }
}

bool CVerInformacionPelicula::validarOpcionMenu(int opcion, int maxOpciones) {
    return (opcion >= 1 && opcion <= maxOpciones);
}

string CVerInformacionPelicula::obtenerTituloPorIndice(int indice) {
    list<DtPelicula> peliculas = manejadorPelicula->listarPeliculas();
    
    if (indice < 0 || indice >= (int)peliculas.size()) {
        return "";
    }
    
    auto it = peliculas.begin();
    advance(it, indice);
    return it->getTitulo();
}

CVerInformacionPelicula::~CVerInformacionPelicula() {
    // No necesitamos liberar manejadorPelicula ni manejadorCine 
    // porque son singletons manejados por el sistema
}