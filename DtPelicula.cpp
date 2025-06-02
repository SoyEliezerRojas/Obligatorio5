#include "DtPelicula.h"
#include "DtCine.h"
DtPelicula::DtPelicula(){}
DtPelicula::DtPelicula(string titulo, string sinopsis,float poster,float PuntajePromedio){
	this->titulo=titulo;
	this->sinopsis=sinopsis;
	this->poster=poster;
	this->PuntajePromedio=PuntajePromedio;
}
string DtPelicula::gettitulo(){
	return this->titulo;
}
string DtPelicula::getsinopsis(){
	return this->sinopsis;
}
string DtPelicula::getposter(){
	return this->poster;
}
float DtPelicula::getPuntajePromedio(){
	return this->PuntajePromedio;
}
DtPelicula::~DtPelicula(){}

ostream& operator <<(ostream& salida, const DtPelicula& dtp){
	cout << "Titulo: " << dtp.titulo << "\n" 
		"Sinopsis: " << dtp.sinopsis << "\n"
		"poster: " << dtp.poster << " \n"
		"Puntaje Promedio: " << dtp.PuntajePromedio << " puntos\n"<<endl;
	return salida;
}
