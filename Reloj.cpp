#include "Reloj.h"
#include <ctime>
#include <sstream>
#include <iomanip>

Reloj* Reloj::instancia = nullptr;

Reloj::Reloj() {
    fechaModificadaManualmente = false;
    // Siempre inicializar con la hora actual del sistema
    obtenerFechaHoraSistema();
}

Reloj* Reloj::getInstancia() {
    if (instancia == nullptr) {
        instancia = new Reloj();
    }
    return instancia;
}



void Reloj::modificarFechaHora(DtFecha fecha, string hora) {
    fechaActual = fecha;
    horaActual = hora;
    fechaModificadaManualmente = true;
    // No guardar en archivo - no persistir entre ejecuciones
}

DtFecha Reloj::getFechaActual() {
    return fechaActual;
}

string Reloj::getHoraActual() {
    return horaActual;
}

string Reloj::getFechaHoraFormateada() {
    if (!fechaModificadaManualmente) {
        // Si no se ha modificado manualmente, mostrar hora actual del sistema
        obtenerFechaHoraSistema();
    }
    
    stringstream ss;
    ss << setfill('0') << setw(2) << fechaActual.getDia() << "/"
       << setfill('0') << setw(2) << fechaActual.getMes() << "/"
       << fechaActual.getAnio() << " " << horaActual;
    return ss.str();
}

void Reloj::obtenerFechaHoraSistema() {
    time_t t = time(0);
    struct tm* now = localtime(&t);
    
    fechaActual = DtFecha(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
    
    stringstream ss;
    ss << setfill('0') << setw(2) << now->tm_hour << ":" 
       << setfill('0') << setw(2) << now->tm_min;
    horaActual = ss.str();
}

Reloj::~Reloj() {
    // No guardar estado al destruir - no persistir entre ejecuciones
} 