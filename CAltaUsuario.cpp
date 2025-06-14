#include "CAltaUsuario.h"
#include "ManejadorUsuario.h"
#include <iostream>
#include <string>
using namespace std;

bool CAltaUsuario::verificarNickname(string nickname) {
	ManejadorUsuario* mU = ManejadorUsuario::getInstancia();
	return !mU->existeUsuario(nickname);
}

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