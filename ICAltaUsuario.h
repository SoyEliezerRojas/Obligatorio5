#ifndef ICALTAUSUARIO
#define ICALTAUSUARIO
#include<string>
using namespace std;

class ICAltaUsuario{
public:        
    virtual void altaUsuario(string, string, string) = 0;
    virtual bool verificarNickname(string) = 0;
    virtual ~ICAltaUsuario(){}
};
#endif