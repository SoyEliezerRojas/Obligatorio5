#include "CAltaUsuario.h"
#include "ManejadorUsuario.h"
#include <iostream>
#include <string>
using namespace std;

void CAltaUsuario::altaUsuario(string nickname,string password, string url){

	ManejadorUsuario* mU = ManejadorUsuario::getInstancia();
    Usuario* usuario;
	try{
		usuario=new Usuario(nickname,password,url);
	}catch(exception e){
	}

    mU->agregarUsuario(usuario);
	cout << "SE HA REGISTRADO EL SOCIO:\n"
     << " NickName: " << nickname
     << "\n PASS: " << password
     << "\n URL: " << url
     << endl;
}