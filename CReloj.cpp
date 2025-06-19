#include "CReloj.h"
#include <stdexcept>
#include <sstream>

CReloj::CReloj() {}

bool CReloj::hayUsuarioLogueado() {
    return Sesion::getInstancia()->getUsuario() != nullptr;
}

void CReloj::modificarFecha(string fechaHora) {
    if (!hayUsuarioLogueado()) {
        throw invalid_argument("ERROR: Debe iniciar sesión para modificar la fecha del sistema.");
    }
    
    if (!validarFormato(fechaHora)) {
        throw invalid_argument("ERROR: Formato inválido. Use dd/mm/aaaa hh:mm");
    }
    
    DtFecha fecha = parsearFecha(fechaHora);
    string hora = parsearHora(fechaHora);
    
    // Validar fecha y hora
    if (!validarFecha(fecha.getDia(), fecha.getMes(), fecha.getAnio())) {
        throw invalid_argument("ERROR: Fecha inválida.");
    }
    
    if (!validarHora(hora)) {
        throw invalid_argument("ERROR: Hora inválida. Use formato hh:mm (00:00 - 23:59)");
    }
    
    Reloj::getInstancia()->modificarFechaHora(fecha, hora);
}

string CReloj::consultarFecha() {
    if (!hayUsuarioLogueado()) {
        throw invalid_argument("ERROR: Debe iniciar sesión para consultar la fecha del sistema.");
    }
    
    return Reloj::getInstancia()->getFechaHoraFormateada();
}

bool CReloj::validarFormato(string fechaHora) {
    // Validar formato exacto dd/mm/aaaa hh:mm
    if (fechaHora.length() != 16) return false;
    if (fechaHora[2] != '/' || fechaHora[5] != '/') return false;
    if (fechaHora[10] != ' ' || fechaHora[13] != ':') return false;
    
    // Validar que los caracteres sean dígitos en las posiciones correctas
    for (int i = 0; i <= 1; i++) {
        if (!isdigit(fechaHora[i])) return false;
    }
    for (int i = 3; i <= 4; i++) {
        if (!isdigit(fechaHora[i])) return false;
    }
    for (int i = 6; i <= 9; i++) {
        if (!isdigit(fechaHora[i])) return false;
    }
    for (int i = 11; i <= 12; i++) {
        if (!isdigit(fechaHora[i])) return false;
    }
    for (int i = 14; i <= 15; i++) {
        if (!isdigit(fechaHora[i])) return false;
    }
    
    return true;
}

DtFecha CReloj::parsearFecha(string fechaHora) {
    // Extraer día, mes, año de dd/mm/aaaa hh:mm
    int dia = stoi(fechaHora.substr(0, 2));
    int mes = stoi(fechaHora.substr(3, 2));
    int anio = stoi(fechaHora.substr(6, 4));
    
    return DtFecha(dia, mes, anio);
}

string CReloj::parsearHora(string fechaHora) {
    // Extraer hora de dd/mm/aaaa hh:mm
    return fechaHora.substr(11, 5);
}

bool CReloj::validarFecha(int dia, int mes, int anio) {
    if (mes < 1 || mes > 12) return false;
    if (dia < 1 || dia > 31) return false;
    if (anio < 1900 || anio > 2100) return false;
    
    // Validar días por mes
    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Año bisiesto
    if (mes == 2) {
        bool bisiesto = (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
        if (bisiesto && dia > 29) return false;
        if (!bisiesto && dia > 28) return false;
    } else {
        if (dia > diasPorMes[mes - 1]) return false;
    }
    
    return true;
}

bool CReloj::validarHora(string hora) {
    if (hora.length() != 5) return false;
    if (hora[2] != ':') return false;
    
    for (int i = 0; i < 5; i++) {
        if (i != 2 && !isdigit(hora[i])) return false;
    }
    
    int horas = stoi(hora.substr(0, 2));
    int minutos = stoi(hora.substr(3, 2));
    
    return (horas >= 0 && horas <= 23 && minutos >= 0 && minutos <= 59);
}

CReloj::~CReloj() {} 