
/*SE GUARDA ESTE BACKUP DE PROYECTO ANTERIOR PARA MANTENER IDEA*/
#include "DtFecha.h"
#include "DtConsulta.h"
#include "DtMascota.h"
#include "DtPerro.h"
#include "DtGato.h"
#include "RazaPerro.h"
#include "Genero.h"
#include "TipoPelo.h"

#include "Fabrica.h"
#include "IControlador.h"

Fabrica* fabrica;
IControlador* icon;

//OPERACION A
void registrarSocio();
//OPERACION B
void agregarMascota();
//OPERACION C
void ingresarConsulta();
//OPERACION D
void verConsultasAntesDeFecha();
//OPERACION E
void eliminarSocio();
//OPERACION F
void obtenerMascotas();

void menu();



//OPERACION A
void registrarSocio(){
	system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"______R E G I S T R O__D E__ S O C I O_______"<< endl;
	string ci, nombreS, nombreM;
	int opGenero,opMascota,opRaza,opVacuna,opPelo;
	float peso;
	Genero genero;
	RazaPerro raza;
	TipoPelo pelo;
	DtPerro dtPerro;
	DtGato dtGato;
	bool vacuna;
	cout << "NOMBRE: ";
	cin >> nombreS;
	cout << endl << "CI: ";
	cin >> ci;
	cout << endl << "DATOS_DE_SU_MASCOTA" << endl;
	cout << "NOMBRE: ";
	cin >> nombreM;
	cout << endl <<"GENERO" << endl << "\t1.Macho\n\t2.Hembra"<<endl<<"INDIQUE: ";
	cin >> opGenero;
	switch(opGenero){
		case 1: genero=MACHO;
			break;
		case 2: genero=HEMBRA;
			break;
	}
	cout << endl <<"PESO: ";
	cin >> peso;
	cout << endl;
	cout << "TIPO MASCOTA\n\t1.Perro\n\t2.Gato"<< endl <<"INDIQUE: ";
	cin >> opMascota;
	switch(opMascota){
		case 1: cout << "RAZA\n\t1.Labrador\n\t2.Ovejero\n\t3.Bulldog\n\t4.Pitbull\n\t5.Collie\n\t6.Pekines\n\t7.Otro"<<endl <<"INDIQUE: ";
			cin >> opRaza;
			switch(opRaza){
				case 1: raza=LABRADOR;
					break;
				case 2: raza=OVEJERO;
					break;
				case 3: raza=BULLDOG;
					break;
				case 4: raza=PITBULL;
					break;
				case 5: raza=COLLIE;
					break;
				case 6: raza=PEKINES;
					break;
				case 7: raza=OTRO;
					break;
			}
			cout << "Tiene vacuna?\n\t1.Si\n\t2.No"<<endl <<"INDIQUE: ";
			cin >> opVacuna;
			vacuna=(opVacuna==1)?true:false;
			dtPerro = DtPerro(nombreM,genero,peso,0,raza,vacuna);
			icon->registrarSocio(ci,nombreS,dtPerro);
			break;
		case 2:
			cout << "PELO\n\t1.Corto\n\t2.Mediano\n\t3.Largo"<<endl <<"INDIQUE: ";
			switch(opPelo){
				case 1: pelo=CORTO;
					break;
				case 2: pelo=MEDIANO;
					break;
				case 3: pelo=LARGO;
					break;
			}
			dtGato=DtGato(nombreM,genero,peso,0,pelo);
			icon->registrarSocio(ci,nombreS,dtGato);
			break;
	}
}

//OPERACION B
void agregarMascota(){
	system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"____R E G I S T R O__D E__ M A S C O T A_____"<< endl;
	string ci, nombreS, nombreM;
	int opGenero,opMascota,opRaza,opVacuna,opPelo;
	float peso;
	Genero genero;
	RazaPerro raza;
	TipoPelo pelo;
	DtPerro dtPerro;
	DtGato dtGato;
	bool vacuna;
	cout << "CI: ";
	cin >> ci;
	try{
		icon->existeSocio(ci);
		cout << "\nDATOS DE SU NUEVA MASCOTA" << endl;
		cout << "NOMBRE: " << endl;
		cin >> nombreM;
		cout << "\nGENERO" << endl << "\t1.Macho\n\t2.Hembra\nINDIQUE: "<<endl;
		cin >> opGenero;
		switch(opGenero){
			case 1: genero=MACHO;
				break;
			case 2: genero=HEMBRA;
				break;
		}
		cout << "\nPESO: ";
		cin >> peso;
		cout << "\nTIPO MASCOTA\n\t1.Perro\n\t2.Gato\nINDIQUE: " << endl;
		cin >> opMascota;
		switch(opMascota){
			case 1: cout << "RAZA\n\t1.Labrador\n\t2.Ovejero\n\t3.Bulldog\n\t4.Pitbull\n\t5.Collie\n\t6.Pekines\n\t7.Otro\nINDIQUE: "<<endl;
				cin >> opRaza;
				switch(opRaza){
					case 1: raza=LABRADOR;
						break;
					case 2: raza=OVEJERO;
						break;
					case 3: raza=BULLDOG;
						break;
					case 4: raza=PITBULL;
						break;
					case 5: raza=COLLIE;
						break;
					case 6: raza=PEKINES;
						break;
					case 7: raza=OTRO;
						break;
				}
				cout << "Tiene vacuna?\n\t1.Si\n\t2.No\nINDIQUE: " << endl;
				cin >> opVacuna;
				vacuna=(opVacuna==1)?true:false;
				dtPerro = DtPerro(nombreM,genero,peso,0,raza,vacuna);
				icon->agregarMascota(ci,dtPerro);
				break;
			case 2:
				cout << "PELO\n\t1.Corto\n\t2.Mediano\n\t3.Largo\nINDIQUE: ";
				switch(opPelo){
					case 1: pelo=CORTO;
						break;
					case 2: pelo=MEDIANO;
						break;
					case 3: pelo=LARGO;
						break;
				}
				dtGato=DtGato(nombreM,genero,peso,0,pelo);
			  icon->agregarMascota(ci,dtGato);
				break;
		}
	}catch(invalid_argument& e){
		cout << e.what() << endl;
	}
}
//OPERACION C
void ingresarConsulta(){
	system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"_____R E G I S T R A R___C O N S U L T A_____"<< endl;
	string ci,motivo;
	int dia,mes,anio;
	DtFecha dtFecha;
	cout << "CI: ";
	cin >> ci;
	try{
		icon->existeSocio(ci);
		cout << endl;
		cout << "MOTIVO: ";
		cin >> motivo;
		cout << endl;
		cout << "DIA: ";
		cin >> dia;
		cout << endl;
		cout << "MES: ";
		cin >> mes;
		cout << endl;
		cout << "ANIO: ";
		cin >> anio;
		cout << endl;
		dtFecha=DtFecha(dia,mes,anio);
		icon->ingresarConsulta(motivo,ci,dtFecha);
	}catch(invalid_argument& e){
		cout << e.what() << endl;
	}
}
//OPERACION D
void verConsultasAntesDeFecha(){
	system("clear");
	cout <<"_________________________________________________" <<endl;
	cout <<"__V E R__L I S T A D O__ D E__C O N S U L T A S__"<< endl;
	string ci;
	int dia,mes,anio,cantConsultas, cantMostrar;
	DtFecha dtFecha;
	cout << "CI: ";
	cin >> ci;
	cout << "\nDIA: ";
	cin >> dia;
	cout << "\nMES: ";
	cin >> mes;
	cout << "\nANIO: ";
	cin >> anio;
	cout << "\nCuantas consultas?: ";
	cin >> cantConsultas;
	dtFecha = DtFecha(dia,mes,anio);
	cout << "\nCONSULTAS ANTES DE " << dia << "/" << mes << "/" << anio << ": " << endl;
	list<DtConsulta*> consultas = icon->verConsultasAntesDeFecha(dtFecha,ci,cantConsultas);
    for (list<DtConsulta*>::iterator it=consultas.begin(); it != consultas.end(); ++it)
		cout << "\n\n" << *it;
}
//OPERACION E
void eliminarSocio(){
	system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"_________E L I M I N A R__S O C I O__________"<< endl;
	string ci;
	cout << "CI: ";
	cin >> ci;
	cout << endl;
	try{
		icon->existeSocio(ci);
		icon->eliminarSocio(ci);
		cout << "SE HA ELIMINADO EL SOCIO DE CI: "<< ci <<endl;
	}catch(invalid_argument& e){
		cout << e.what() << endl;
	}
}
//OPERACION F
void obtenerMascotas(){
	system("clear");
	cout <<"_________________________________________________" <<endl;
	cout <<"___V E R__L I S T A D O__ D E__M A S C O T A S___"<< endl;
	string ci;
	int cantMascotas;
	DtPerro* perro;
	DtGato* gato;
	cout << "CI: ";
	cin >> ci;
	cout << endl;
	try{
		icon->existeSocio(ci);
		cout << "Cuantas mascotas?: ";
		cin >> cantMascotas;
		cout << endl;
		list<DtMascota*> dtMascotas = icon->obtenerMascotas(ci,cantMascotas);
		cout << "MASCOTAS DEL SOCIO DE CI: " << ci <<endl;
        for (list<DtMascota*>::iterator it=dtMascotas.begin(); it != dtMascotas.end(); ++it){
			perro = dynamic_cast<DtPerro*>(*it);
			if (perro!=NULL)
				cout << "\n\n" << *(perro);
			else{
				gato = dynamic_cast<DtGato*>(*it);
				if (gato!=NULL)
					cout << "\n\n" << *(gato);	
			}
			cout << "-------------------------"<< endl;	
		}
	}catch(invalid_argument& e){
		cout << e.what() << endl;
	}
}
void menu(){
		system("clear");
		cout <<"_____________________________________________" <<endl;
		cout <<"____________V E T E R I N A R I A____________"<< endl;
		cout <<"1. Registrar Socio"<<endl;
		cout <<"2. Agregar Mascota"<<endl;
		cout <<"3. Agregar Consulta"<<endl;
		cout <<"4. Ver consultas antes de una fecha"<<endl;
		cout <<"5. Eliminar Socio"<<endl;
		cout <<"6. Obtener Mascotas de un Socio"<<endl;
		cout <<"7. Salir"<<endl;
		cout <<"_____________________________________________" <<endl;
		cout <<"OPCION: ";
}


main(){
	fabrica = Fabrica::getInstancia();
    icon = fabrica->getIControlador(); 
	int opcion;
	icon->cargarDatos();
	menu();
	cin >> opcion;
	while(opcion != 7){
		switch(opcion){
			case 1: registrarSocio();
				break;
			case 2: agregarMascota();
				break;
			case 3: ingresarConsulta();
				break;
			case 4: verConsultasAntesDeFecha();
				break;
			case 5: eliminarSocio();
				break;
			case 6: obtenerMascotas();
				break;
			case 7: system("exit");
				cout << "SALIENDO..." << endl;
			default:
				cout << "OPCIÓN INCORRECTA" << endl;
		}
		system("sleep 5");
		menu();
		cin >> opcion;
	}
}
