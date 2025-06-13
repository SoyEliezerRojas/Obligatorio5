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
        Usuario* usuarioActual;
        ManejadorUsuario();
    public:
        static ManejadorUsuario* getInstancia();
        list<Usuario*> getUsuarios();
        virtual ~ManejadorUsuario();
        void agregarUsuario(Usuario*);
        Usuario* buscarUsuario(string);
        void eliminarUsuario(string);
        bool existeUsuario(string);
        bool verificarCredenciales(string nickname, string password);
        Usuario* getUsuarioActual();
        void setUsuarioActual(Usuario* usuario);
};
#endif