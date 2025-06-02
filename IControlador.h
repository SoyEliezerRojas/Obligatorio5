#ifndef ICONTROLADOR
#define ICONTROLADOR
#include<list>
#include<string>
#include"DtMascota.h"
#include"DtFecha.h"
#include"DtConsulta.h"

using namespace std;

class IControlador{
    public:        
        virtual void registrarSocio(string,string,DtMascota&)=0;
        virtual void agregarMascota(string,DtMascota&)=0;
        virtual void ingresarConsulta(string,string,DtFecha&)=0;
        virtual list<DtConsulta*> verConsultasAntesDeFecha(DtFecha&,string,int&)=0;
        virtual void eliminarSocio(string ci)=0;
        virtual list<DtMascota*> obtenerMascotas(string,int&)=0;
        virtual void cargarDatos() = 0;
        virtual void existeSocio(string) = 0;
};
#endif
