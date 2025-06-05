#ifndef MANEJADORUSUARIO
#define MANEJADORUSUARIO
#include "Usuario.h"
#include <string>
#include <map>
#include <list>

using namespace std;

class ManejadorUsuario{
    private:
        static ManejadorUsuario* instancia;
        map<string,Usuario*> usuarios;
        ManejadorUsuario();
    public:
        static ManejadorUsuario* getInstancia();
        list<Usuario*> getUsuarios();
        virtual ~ManejadorUsuario();
        void agregarUsuario(Usuario*);
        Usuario* buscarUsuario(string);
        void eliminarUsuario(string);
        bool existeUsuario(string);
};
#endif