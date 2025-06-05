#ifndef CALTAUSUARIO
#define CALTAUSUARIO
#include "ICAltaUsuario.h"
#include <string>
using namespace std;


class CAltaUsuario: public ICAltaUsuario{
    public:
        void altaUsuario(string, string, string);
};
#endif