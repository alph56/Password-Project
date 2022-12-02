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

void GenPass::escribir() {
	ofstream password;

	password.open("Pass.txt", ios::out);
	if (password.fail()) {
		cout<<"\nNo se pudo abrir el archivo"<<endl;
			exit(1);
	}
	password << getcontrasenhia();

	password.close;
}