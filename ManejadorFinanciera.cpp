#include "ManejadorFinanciera.h"

ManejadorFinanciera* ManejadorFinanciera::instancia = nullptr;

ManejadorFinanciera::ManejadorFinanciera() {
    // Inicializar con financieras predeterminadas
    this->agregarFinanciera(new Financiera("Visa", 10.0));
    this->agregarFinanciera(new Financiera("Mastercard", 15.0));
    this->agregarFinanciera(new Financiera("American Express", 20.0));
    this->agregarFinanciera(new Financiera("Diners", 5.0));
}

ManejadorFinanciera* ManejadorFinanciera::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ManejadorFinanciera();
    }
    return instancia;
}

void ManejadorFinanciera::agregarFinanciera(Financiera* financiera) {
    this->financieras.push_back(financiera);
}

Financiera* ManejadorFinanciera::buscarFinanciera(string nombre) {
    for (list<Financiera*>::iterator it = financieras.begin(); it != financieras.end(); ++it) {
        if ((*it)->getNombre() == nombre) {
            return *it;
        }
    }
    return nullptr;
}

float ManejadorFinanciera::obtenerDescuento(string nombre) {
    Financiera* financiera = buscarFinanciera(nombre);
    if (financiera != nullptr) {
        return financiera->getDescuento();
    }
    return 0.0; // Sin descuento si no se encuentra
}

list<Financiera*> ManejadorFinanciera::getFinancieras() {
    return this->financieras;
}

ManejadorFinanciera::~ManejadorFinanciera() {
    // Liberar memoria de las financieras
    for (list<Financiera*>::iterator it = financieras.begin(); it != financieras.end(); ++it) {
        delete *it;
    }
    financieras.clear();
} 