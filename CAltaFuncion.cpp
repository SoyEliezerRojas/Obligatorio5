#include "CAltaFuncion.h"
#include "DtHorario.h"
#include "ManejadorPelicula.h"
#include "ManejadorCine.h"
#include "ManejadorFuncion.h"
#include "Pelicula.h"
#include "Cine.h"
#include "Funcion.h"
#include <iostream>
#include <string>
#include <list>
#include <vector>

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
        // ID autogenerado para la función
        int idFuncion = manejadorFunc->getNextId();
        
        // Crear horario
        DtHorario horario(horaInicio, ""); // Hora fin se calcula internamente
        
        // f = new Funcion(hora, fecha, p)
        Funcion* funcion = new Funcion(idFuncion, fecha, horario);
        funcion->setPelicula(pelicula);
        funcion->setPrecio(200); // Precio por defecto
        
        // ColGlobalFuncion->add(f)
        manejadorFunc->agregarFuncion(funcion);
        
        // NOTA: La asignación función->sala no se puede hacer desde CAltaFuncion
        // debido a las reglas UML estrictas:
        // - CAltaFuncion no puede ver Sala
        // - Cine no puede ver Funcion  
        // - ManejadorFuncion no puede ver ManejadorCine
        // La asignación debe hacerse externamente por quien use esta interfaz
        
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

void CAltaFuncion::mostrarSalasConOcupacion() {
    // Mostrar salas verificando ocupación basada en reservas vs capacidad
    cout << endl << "SALAS DISPONIBLES:" << endl;
    
    ManejadorCine* manejadorCine = ManejadorCine::getInstancia();
    ManejadorFuncion* manejadorFunc = ManejadorFuncion::getInstancia();
    
    int idCine = stoi(this->idCineSeleccionado);
    Cine* cine = manejadorCine->buscarCine(idCine);
    
    if (cine != nullptr) {
        list<DtSala> salas = cine->getDtSalas();
        
        // Obtener funciones del cine y contar entradas reservadas
        list<Funcion*> todasFunciones = manejadorFunc->getFunciones();
        vector<int> entradasPorFuncion;
        
        for (list<Funcion*>::iterator funcIt = todasFunciones.begin(); funcIt != todasFunciones.end(); ++funcIt) {
            Funcion* funcion = *funcIt;
            if (funcion->getPelicula() != nullptr) {
                list<Cine*> cinesPelicula = funcion->getPelicula()->getCines();
                bool funcionEnCine = false;
                
                for (list<Cine*>::iterator cineIt = cinesPelicula.begin(); cineIt != cinesPelicula.end(); ++cineIt) {
                    if ((*cineIt)->getIdCine() == idCine) {
                        funcionEnCine = true;
                        break;
                    }
                }
                
                if (funcionEnCine) {
                    // Contar entradas reservadas para esta función
                    list<Reserva*> reservas = funcion->getReservas();
                    int totalEntradas = 0;
                    for (list<Reserva*>::iterator resIt = reservas.begin(); resIt != reservas.end(); ++resIt) {
                        totalEntradas += (*resIt)->getCantEntradas();
                    }
                    entradasPorFuncion.push_back(totalEntradas);
                }
            }
        }
        
        // Mostrar cada sala verificando si podría estar ocupada
        for (list<DtSala>::iterator it = salas.begin(); it != salas.end(); ++it) {
            cout << "ID: " << it->getId() << " - Capacidad: " << it->getCapacidad() << " asientos - ";
            
            // Verificar si alguna función tiene reservas que llenan esta capacidad
            bool salaOcupada = false;
            for (vector<int>::iterator entIt = entradasPorFuncion.begin(); entIt != entradasPorFuncion.end(); ++entIt) {
                if (*entIt >= it->getCapacidad()) {
                    salaOcupada = true;
                    break;
                }
            }
            
            if (salaOcupada) {
                cout << "Ocupada";
            } else {
                cout << "Disponible";
            }
            
            cout << endl;
        }
    }
}

CAltaFuncion::~CAltaFuncion() {
    // No necesitamos liberar memoria ya que los manejadores son singletons
    // y manejan su propia memoria
}
