#include "CAltaFuncion.h"
#include "DtHorario.h"
#include "ManejadorPelicula.h"
#include "ManejadorCine.h"
#include "ManejadorFuncion.h"
#include "Pelicula.h"
#include "Cine.h"
#include "Funcion.h"
#include "DtFecha.h"
#include "DtPelicula.h"
#include "DtCine.h"
#include "DtSala.h"
#include <string>
#include <list>
#include <vector>
#include <ctime>
#include <map>

using namespace std;

CAltaFuncion::CAltaFuncion() {
    // Inicializar atributos para recordar las selecciones del usuario
    this->tituloPeliculaSeleccionada = "";
    this->idCineSeleccionado = "";
    this->idSalaSeleccionada = 0;
}

list<DtPelicula> CAltaFuncion::listarPeliculas() {
    // Siguiendo diagrama: CAltaFuncion accede a colección global de películas
    // Itera con foreach por todas las películas y retorna DtPelicula con título y poster
    list<DtPelicula> infoPeliculas;
    
    ManejadorPelicula* manejadorPeli = ManejadorPelicula::getInstancia();
    vector<Pelicula*>& peliculas = manejadorPeli->getPeliculas();
    
    // foreach p in ColGlobalPelicula -> p->getDtPelicula()
    for (vector<Pelicula*>::iterator it = peliculas.begin(); it != peliculas.end(); ++it) {
        Pelicula* p = *it;
        DtPelicula dtPeli = p->getDtPelicula();
        infoPeliculas.push_back(dtPeli);
    }
    
    return infoPeliculas;
}

void CAltaFuncion::selectPeli(string titulo) {
    // Siguiendo diagrama: CAltaFuncion recuerda el título seleccionado
    // Busca película usando p->find(titulo) y obtiene sus cines
    this->tituloPeliculaSeleccionada = titulo;
}

list<DtCine> CAltaFuncion::listarCines() {
    // CORREGIDO: Listar TODOS los cines del sistema, no solo los de la película
    // La asociación película-cine se hace al crear la función
    list<DtCine> infoCines;
    
    ManejadorCine* manejadorCine = ManejadorCine::getInstancia();
    list<Cine*> todosCines = manejadorCine->getCines();
    
    // foreach c in ColGlobalCines -> c->getDtCine()
    for (list<Cine*>::iterator it = todosCines.begin(); it != todosCines.end(); ++it) {
        Cine* c = *it;
        // Construir DtCine con id y dirección
        DtCine dtCine(c->getIdCine(), c->getDirecCine());
        infoCines.push_back(dtCine);
    }
    
    return infoCines;
}

void CAltaFuncion::selectCine(string idCine) {
    // Siguiendo diagrama: CAltaFuncion recuerda el ID del cine seleccionado
    this->idCineSeleccionado = idCine;
}

list<DtSala> CAltaFuncion::listarSalas() {
    // Siguiendo reglas UML: CAltaFuncion NO puede ver Sala directamente
    // Debe hacerlo a través de Cine que sí puede ver Sala
    list<DtSala> infoSalas;
    
    ManejadorCine* manejadorCine = ManejadorCine::getInstancia();
    int idCine = stoi(this->idCineSeleccionado);
    Cine* cine = manejadorCine->buscarCine(idCine);
    
    if (cine != nullptr) {
        // Usar el método getDtSalas() implementado en Cine
        infoSalas = cine->getDtSalas();
    }
    
    return infoSalas;
}

void CAltaFuncion::selectSala(int idSala) {
    // Siguiendo diagrama: CAltaFuncion recuerda el ID de la sala seleccionada
    this->idSalaSeleccionada = idSala;
}

void CAltaFuncion::altaFuncion(string horaInicio, DtFecha fecha) {
    // Siguiendo diagrama altaFuncion y respetando reglas UML estrictas
    // CAltaFuncion solo puede crear la función, no asignarla a sala
    
    ManejadorPelicula* manejadorPeli = ManejadorPelicula::getInstancia();
    ManejadorCine* manejadorCine = ManejadorCine::getInstancia();
    ManejadorFuncion* manejadorFunc = ManejadorFuncion::getInstancia();
    
    // Buscar película: p = find(this->titulo)
    Pelicula* pelicula = manejadorPeli->buscarPelicula(this->tituloPeliculaSeleccionada);
    
    // Buscar cine: c = find(Cine)
    int idCine = stoi(this->idCineSeleccionado);
    Cine* cine = manejadorCine->buscarCine(idCine);
    
    if (pelicula != nullptr && cine != nullptr) {
        // Buscar la sala seleccionada
        Sala* salaSeleccionada = cine->buscarSala(this->idSalaSeleccionada);
        if (salaSeleccionada == nullptr) {
            // Manejar error si la sala no se encuentra
            return;
        }

        // ID autogenerado para la función
        int idFuncion = manejadorFunc->getNextId();
        
        // Crear horario
        DtHorario horario(horaInicio, ""); // Hora fin se calcula internamente
        
        // f = new Funcion(...) con la sala
        Funcion* funcion = new Funcion(idFuncion, fecha, horario, salaSeleccionada);
        funcion->setPelicula(pelicula);
        funcion->setPrecio(200); // Precio por defecto
        
        // ColGlobalFuncion->add(f)
        manejadorFunc->agregarFuncion(funcion);
        
        // Asociar la función a la sala (la sala ya lo sabe por el constructor, pero esta llamada puede ser necesaria para la bidireccionalidad)
        salaSeleccionada->agregarFuncion(funcion);
        
        // Asegurar que el cine esté en la lista de cines de la película
        bool cineExiste = false;
        list<Cine*> cinesPelicula = pelicula->getCines();
        for (list<Cine*>::iterator it = cinesPelicula.begin(); it != cinesPelicula.end(); ++it) {
            if ((*it)->getIdCine() == cine->getIdCine()) {
                cineExiste = true;
                break;
            }
        }
        if (!cineExiste) {
            pelicula->agregarCine(cine);
        }
    }
}

bool CAltaFuncion::hayUsuarioLogueado() {
    // Según reglas UML: CAltaFuncion NO puede acceder a Sesion
    // El caso de uso asume usuario ya logueado
    return true;
}

list<DtSala> CAltaFuncion::obtenerSalasConOcupacion() {
    list<DtSala> salasConInfo;
    
    ManejadorCine* manejadorCine = ManejadorCine::getInstancia();
    int idCine = stoi(this->idCineSeleccionado);
    Cine* cine = manejadorCine->buscarCine(idCine);

    if (cine != nullptr) {
        list<Sala*> salas = cine->getSalas();
        for (Sala* sala : salas) {
            DtSala dtSala(sala->getId(), sala->getCapacidad());
            salasConInfo.push_back(dtSala);
        }
    }
    
    return salasConInfo;
}

map<int, string> CAltaFuncion::obtenerInformacionOcupacionSalas() {
    map<int, string> ocupacionSalas;
    
    ManejadorCine* manejadorCine = ManejadorCine::getInstancia();
    int idCine = stoi(this->idCineSeleccionado);
    Cine* cine = manejadorCine->buscarCine(idCine);
    
    // Obtener fecha y hora actual
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    int diaActual = now->tm_mday;
    int mesActual = now->tm_mon + 1;
    int anioActual = now->tm_year + 1900;
    int horaActual = now->tm_hour;
    int minActual = now->tm_min;

    if (cine != nullptr) {
        list<Sala*> salas = cine->getSalas();
        for (Sala* sala : salas) {
            string funcionesCompletas = "";
            int capacidadSala = sala->getCapacidad();
            list<Funcion*> funciones = sala->getFunciones();
            for (Funcion* funcion : funciones) {
                // Solo mostrar funciones que tienen la sala completamente ocupada
                list<Reserva*> reservas = funcion->getReservas();
                if (!reservas.empty()) {
                    // Contar el total de entradas reservadas para esta función
                    int totalEntradasReservadas = 0;
                    for (Reserva* reserva : reservas) {
                        totalEntradasReservadas += reserva->getCantEntradas();
                    }
                    
                    // Solo mostrar si la sala está completamente ocupada
                    if (totalEntradasReservadas >= capacidadSala) {
                        DtFecha fecha = funcion->getDiaFun();
                        DtHorario horario = funcion->getHoraFun();
                        int dia = fecha.getDia();
                        int mes = fecha.getMes();
                        int anio = fecha.getAnio();
                        string horaStr = horario.getHoraIni();
                        int hora, minuto;
                        sscanf(horaStr.c_str(), "%d:%d", &hora, &minuto);
                        // Comparar fecha y hora actual con la de la función
                        bool esFutura = false;
                        if (anio > anioActual ||
                            (anio == anioActual && mes > mesActual) ||
                            (anio == anioActual && mes == mesActual && dia > diaActual) ||
                            (anio == anioActual && mes == mesActual && dia == diaActual && (hora > horaActual || (hora == horaActual && minuto >= minActual)))) {
                            esFutura = true;
                        }
                        if (esFutura) {
                            if (!funcionesCompletas.empty()) funcionesCompletas += ", ";
                            funcionesCompletas += to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio) + " " + horaStr + " (" + funcion->getPelicula()->getTitulo() + ")";
                        }
                    }
                }
            }
            ocupacionSalas[sala->getId()] = funcionesCompletas;
        }
    }
    
    return ocupacionSalas;
}

CAltaFuncion::~CAltaFuncion() {
    // No necesitamos liberar memoria ya que los manejadores son singletons
    // y manejan su propia memoria
}
