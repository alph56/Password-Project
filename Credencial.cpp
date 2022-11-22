#include "Credencial.h"

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