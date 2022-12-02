#include"GenPass.h"
#include<cstdlib>
#include<ctime>
#include<string>
#include<fstream>
#include<stdlib.h>

using namespace std;

GenPass::GenPass() {
	contrasenhia = "Unknown";
}

void GenPass::setcontrasenhia(string contrasenhia) {
	this->contrasenhia = contrasenhia;
	escribir();
}

string GenPass::getcontrasenhia(void) {
	return contrasenhia;
}

void GenPass::RandomPass(int lenght) {
	static const char alphanum[] = "1234567890ABCDEFGHIJKLNMOPQRSTUVWXYZ!#$%&*+@~_-abcdefghijklmnopqrstuvwxyz";
	int string_lenght = sizeof(alphanum);
	srand(time(0));
	char pass[lenght];
	cout << "Contrasena generada: ";
	for (int i = 0; i < lenght; i++) {
		pass[i] = alphanum[rand() % string_lenght];
		cout << pass[i];
		setcontrasenhia(pass);
		escribir();
	}
}

void GenPass::escribir(void) {
	ofstream password;

	password.open("Pass.txt", ios::out);
	if (password.fail()) {
		cout<<"\nNo se pudo abrir el archivo"<<endl;
			exit(1);
	}
  else{
    string str=getcontrasenhia();
    int size1=(getcontrasenhia().size());

     password.write(reinterpret_cast<char *>(&size1), sizeof(int));
     password.write(getcontrasenhia().c_str(), size1);
  }
	//password << getcontrasenhia();
  password.flush();
	password.close();
}

void GenPass::leer(void){
  ofstream password;
  ifstream leerpassword;
  if (password.fail()) {
		cout<<"\nNo se pudo abrir el archivo Pass.txt"<<endl;
			exit(1);
	}
  else{
    char *buf;
    string str=getcontrasenhia();
    int size1=(getcontrasenhia().size());
    
    leerpassword.read(reinterpret_cast<char *>(&size1), sizeof(int));
    buf = new char[size1];
    leerpassword.read( buf, size1);
    getcontrasenhia()= "";
    getcontrasenhia().append(buf, size1); 
  }
}