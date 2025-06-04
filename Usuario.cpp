#include "Usuario.h"
#include <string>
using namespace std;

Usuario::Usuario() {}

Usuario::Usuario(string nickN, string pass, string url) {
    this->nickName = nickN;
    this->pass = pass;
    this->urlFoto = url;
}

bool Usuario::verificarPass(string& pass) {
    return this->pass == pass;
}


string Usuario::getNickName() {
    return this->nickName;
}

void Usuario::setNickName(string nickN) {
    this->nickName = nickN;
}

string Usuario::getPass() {
    return this->pass;
}

void Usuario::setPass(string pass) {
    this->pass = pass;
}

string Usuario::getUrlFoto() {
    return this->urlFoto;
}

void Usuario::setUrl(string url) {
    this->urlFoto = url;
}

Usuario::~Usuario() {}