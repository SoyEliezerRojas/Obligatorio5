#ifndef MANEJADORFINANCIERA_H
#define MANEJADORFINANCIERA_H

#include "Financiera.h"
#include <list>
#include <string>
using namespace std;

class ManejadorFinanciera {
private:
    static ManejadorFinanciera* instancia;
    list<Financiera*> financieras;
    
    ManejadorFinanciera(); // Constructor privado

public:
    static ManejadorFinanciera* getInstancia();
    
    void agregarFinanciera(Financiera* financiera);
    Financiera* buscarFinanciera(string nombre);
    float obtenerDescuento(string nombre);
    list<Financiera*> getFinancieras();
    
    ~ManejadorFinanciera();
};

#endif 