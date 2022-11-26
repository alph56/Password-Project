#include "Credencial.h"
#include <iostream>
using namespace std;

Credencial::Credencial(string usuario,string password,string dominio){
  this->usuario=usuario;
  this->password=password;
  this->dominio=dominio;
}

Credencial::Credencial(){
  dominio=" ";
  password=" ";
  usuario=" ";
}

void Credencial::Setpassword(string password){
  this->password=password;
}
string Credencial::Getpassword(void){
  return password;
}

void Credencial::SetUsuario(string usuario){
  this->usuario=usuario;
}
string Credencial::Getusuario(void){
  return usuario;
}