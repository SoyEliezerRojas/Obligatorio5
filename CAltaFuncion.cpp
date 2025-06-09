#include "CAltaFuncion.h"
#include "DtHorario.h"

CAltaFuncion::CAltaFuncion() {
    this->peliculaSeleccionada = NULL;
    this->cineSeleccionado = NULL;
    this->salaSeleccionada = NULL;
}

list<DtPelicula> CAltaFuncion::listarPeliculas() {
    ManejadorPelicula* mP = ManejadorPelicula::getInstancia();
    return mP->listarPeliculas();
}

void CAltaFuncion::selectPeli(string titulo) {
    ManejadorPelicula* mP = ManejadorPelicula::getInstancia();
    this->peliculaSeleccionada = mP->buscarPelicula(titulo);
}

list<DtCine> CAltaFuncion::listarCines() {
    ManejadorCine* mC = ManejadorCine::getInstancia();
    list<DtCine> infoCines;
    
    list<Cine*> cines = mC->getCines();
    for(list<Cine*>::iterator c = cines.begin(); c != cines.end(); ++c) {
        DtCine dtC((*c)->getIdCine(), (*c)->getDirecCine());
        infoCines.push_back(dtC);
    }
    return infoCines;
}

void CAltaFuncion::selectCine(string id) {
    ManejadorCine* mC = ManejadorCine::getInstancia();
    this->cineSeleccionado = mC->buscarCine(stoi(id));
}

list<DtSala> CAltaFuncion::listarSalas() {
    list<DtSala> infoSalas;
    if (this->cineSeleccionado != NULL) {
        list<Sala*> salas = this->cineSeleccionado->getSalas();
        for (list<Sala*>::iterator s = salas.begin(); s != salas.end(); ++s) {
            DtSala dtSala((*s)->getId(), (*s)->getCapacidad());
            infoSalas.push_back(dtSala);
            
            cout << "Funciones de la sala " << (*s)->getId() << ":" << endl;
            list<Funcion*> funciones = (*s)->getFunciones();
            if (funciones.empty()) {
                cout << "  No hay funciones programadas" << endl;
            } else {
                for (list<Funcion*>::iterator f = funciones.begin(); f != funciones.end(); ++f) {
                    cout << "  Hora: " << (*f)->getHoraFun().getHoraIni() << " - Fecha: " 
                         << (*f)->getDiaFun().getDia() << "/" 
                         << (*f)->getDiaFun().getMes() << "/" 
                         << (*f)->getDiaFun().getAnio() << endl;
                }
            }
        }
    }
    return infoSalas;
}

void CAltaFuncion::selectSala(int id) {
    if (this->cineSeleccionado != NULL) {
        list<Sala*> salas = this->cineSeleccionado->getSalas();
        for(list<Sala*>::iterator s = salas.begin(); s != salas.end(); ++s) {
            if ((*s)->getId() == id) {
                this->salaSeleccionada = *s;
                break;
            }
        }
    }
}

void CAltaFuncion::altaFuncion(int id, string horaInicio, DtFecha fecha) {
    if (this->peliculaSeleccionada != NULL && this->cineSeleccionado != NULL && this->salaSeleccionada != NULL) {
        // Crear el DtHorario con hora inicio y fin (asumimos que cada función dura 2 horas)
        string horaFin = horaInicio; // TODO: calcular hora fin basado en hora inicio
        DtHorario horario(horaInicio, horaFin);
        
        // Crear nueva función con los datos proporcionados
        Funcion* f = new Funcion(id, fecha, horario);
        
        // Agregar la función a la sala
        this->salaSeleccionada->agregarFuncion(f);
        
        // Guardar la función en el manejador
        ManejadorFuncion::getInstancia()->agregarFuncion(f);
    }
}

CAltaFuncion::~CAltaFuncion() {
    // No necesitamos eliminar los punteros ya que son manejados por sus respectivos manejadores
    this->peliculaSeleccionada = NULL;
    this->cineSeleccionado = NULL;
    this->salaSeleccionada = NULL;
}
