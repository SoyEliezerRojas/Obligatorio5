#include "Controlador.h"
#include "DtGato.h"
#include "DtPerro.h"
#include "DtMascota.h"
#include "Mascota.h"
#include "Gato.h"
#include "Perro.h"
#include "Consulta.h"
#include "Socio.h"
#include "ManejadorSocio.h"
void Controlador::registrarSocio(string ci,string nombre,DtMascota& dtMascota){
	ManejadorSocio* mS = ManejadorSocio::getInstancia();
    Socio* socio;
	try{
		DtPerro& dtPerro = dynamic_cast<DtPerro&>(dtMascota);
		Perro* perro = new Perro(dtPerro.getNombre(),dtPerro.getGenero(),dtPerro.getPeso(),dtPerro.getRaza(),dtPerro.getVacunaCachorro());
		socio=new Socio(ci,nombre,perro);
	}catch(bad_cast){
		try{
			DtGato& dtGato = dynamic_cast<DtGato&>(dtMascota);
			Gato* gato = new Gato(dtGato.getNombre(),dtGato.getGenero(),dtGato.getPeso(),dtGato.getTipoPelo());
			socio=new Socio(ci,nombre,gato);
		}catch(bad_cast){}
	}
    mS->agregarSocio(socio);
	cout << "SE HA REGISTRADO EL SOCIO " << nombre << " DE CI: " << ci << " Y SU MASCOTA "<< dtMascota.getNombre() << endl;
}



void Controlador::agregarMascota(string ci,DtMascota& dtMascota){
	ManejadorSocio* mS = ManejadorSocio::getInstancia();
    Socio* socio = mS->buscarSocio(ci);
	try{
		DtPerro& dtPerro = dynamic_cast<DtPerro&>(dtMascota);
		Perro* perro = new Perro(dtPerro.getNombre(),dtPerro.getGenero(),dtPerro.getPeso(),dtPerro.getRaza(),dtPerro.getVacunaCachorro());
		socio->agregarMascota(perro);
		cout << "SE AGREGO LA MASCOTA " << dtMascota.getNombre() << " AL SOCIO DE CI: " << ci << endl;
	}catch(bad_cast){
		try{
			DtGato& dtGato = dynamic_cast<DtGato&>(dtMascota);
			Gato* gato = new Gato(dtGato.getNombre(),dtGato.getGenero(),dtGato.getPeso(),dtGato.getTipoPelo());
			socio->agregarMascota(gato);
			cout << "SE AGREGO LA MASCOTA " << dtMascota.getNombre() << " AL SOCIO DE CI: " << ci << endl;
		}catch(bad_cast){}
	}

}


void Controlador::ingresarConsulta(string motivo,string ci,DtFecha& dtFecha){
	ManejadorSocio* mS = ManejadorSocio::getInstancia();
    Socio* socio = mS->buscarSocio(ci);
	Consulta* consulta = new Consulta(dtFecha,motivo);
	socio->agregarConsulta(consulta);
	cout << "SE HA INGRESADO LA CONSULTA CORRECTAMENTE AL SOCIO DE CI: " << ci <<endl;
}


list<DtConsulta*> Controlador::verConsultasAntesDeFecha(DtFecha& dtFecha,string ci,int& cantConsultas){
	ManejadorSocio* mS = ManejadorSocio::getInstancia();
    Socio* socio = mS->buscarSocio(ci);
	if(cantConsultas>socio->getTopeConsultas())
		cantConsultas=socio->getTopeConsultas();
	Consulta** consultas = socio->obtenerConsultas();
	list<DtConsulta*> dtConsultas;
	DtConsulta* dtConsulta;
	int i=0,j=0;
	while(i<cantConsultas){
		cout << consultas[j]->getMotivo() << endl;
		if ((consultas[j]->getFechaConsulta()) < dtFecha){
			dtConsulta= new DtConsulta(consultas[i]->getFechaConsulta(),consultas[i]->getMotivo());
			dtConsultas.push_back(dtConsulta);
			i++;
		}
		j++;
	}
	return dtConsultas;
}

void Controlador::eliminarSocio(string ci){
	ManejadorSocio* mS = ManejadorSocio::getInstancia();
    Socio* socio = mS->buscarSocio(ci);
    mS->eliminarSocio(ci);
	delete socio;
}

list<DtMascota*> Controlador::obtenerMascotas(string ci,int& cantMascotas){
	ManejadorSocio* mS = ManejadorSocio::getInstancia();
    Socio* socio = mS->buscarSocio(ci);
	Mascota** mascotas = socio->obtenerMascotas();
	DtPerro* dtPerro;
	DtGato* dtGato;
	if(cantMascotas>socio->getTopeMascotas())
		cantMascotas=socio->getTopeMascotas();
	list<DtMascota*> dtMascotas;
	for(int i=0;i<cantMascotas;i++){
		if(Perro* perro = dynamic_cast<Perro*>(mascotas[i])){
				dtPerro = new DtPerro(perro->getNombre(),perro->getGenero(),perro->getPeso(),perro->obtenerRacionDiaria(),perro->getRaza(),perro->getVacunaCachorro());
				dtMascotas.push_back(dtPerro);
		}else{
			if(Gato* gato = dynamic_cast<Gato*>(mascotas[i])){
					dtGato = new DtGato(gato->getNombre(),gato->getGenero(),gato->getPeso(),gato->obtenerRacionDiaria(),gato->getTipoPelo());
					dtMascotas.push_back(dtGato);
			}
		}
	}
	return dtMascotas;
}




void Controlador::existeSocio(string ci){
	ManejadorSocio* mS = ManejadorSocio::getInstancia();
	bool existe=mS->existeSocio(ci);
	if (!existe)
		throw invalid_argument("ERROR: NO EXISTE USUARIO CON ESA CI EN EL SISTEMA\n");
}


void Controlador::cargarDatos(){
	//REGISTRANDO SOCIOS
	DtPerro dtp= DtPerro("Billi",MACHO,11,0,LABRADOR,true);
	DtGato dtg= DtGato("Tom",MACHO,6,0,CORTO);
	registrarSocio("49335620","Yonathan",dtp);
	registrarSocio("40037741","Cristhian",dtg);
	//REGISTRANDO MASCOTAS A SOCIOS
	DtPerro dtp1= DtPerro("Kinki",HEMBRA,9,0,OVEJERO,false);
	DtGato dtg2= DtGato("Maniri",HEMBRA,3,0,LARGO);
	agregarMascota("49335620",dtp1);
	agregarMascota("40037741",dtg2);
	agregarMascota("40037741",dtp1);
	//REGISTRANDO CONSULTAS
	DtFecha f15 = DtFecha(1,1,2015);
	DtFecha f16 = DtFecha(1,1,2016);
	DtFecha f17 = DtFecha(1,1,2017);
	DtFecha f18 = DtFecha(1,1,2018);
	ingresarConsulta("Consulta del 2015","49335620",f15);
	ingresarConsulta("Consulta del 2016","49335620",f16);
	ingresarConsulta("Consulta del 2017","49335620",f17);
	ingresarConsulta("Consulta del 2018","49335620",f18);
	ingresarConsulta("Consulta del 2015","40037741",f15);
	ingresarConsulta("Consulta del 2016","40037741",f16);
	ingresarConsulta("Consulta del 2017","40037741",f17);
	ingresarConsulta("Consulta del 2018","40037741",f18);
}

