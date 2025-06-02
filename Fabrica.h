#ifndef FABRICA
#define FABRICA
#include "IControlador.h"
class Fabrica{
    private:
        static Fabrica* instancia;
        Fabrica();
    public:
        static Fabrica* getInstancia();
        IControlador* getIControlador();
        ~Fabrica();
};
#endif
