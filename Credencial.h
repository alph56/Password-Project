#ifndef CREDENCIAL_H
#define CREDENCIAL_H
#include <iostream>
using namespace std;

class Credencial{
public:
Credencial();
Credencial(string,string,string);

string dominio; 
void SetUsuario(string usuario);
void Setpassword(string password);

string Getusuario(void);
string Getpassword(void);


Private:
string usuario;
string password; 
};


#endif//Credencial