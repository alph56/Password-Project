#include"GenPass.h"
#include<cstdlib>
#include<ctime>
#include<string>

using namespace std;

GenPass::GenPass() {
	contrasenhia = "Unknown";
}

void GenPass::setcontrasenhia(string contrasenhia) {
	this->contrasenhia = contrasenhia;
}
string GenPass::getcontrasenhia(void) {
	return contrasenhia;
}

void GenPass::Manual(string contra) {
	string contra;
	cout << "Ingrese su nueva contrasena: ";
	fflush(stdin);
	cin >> contra;
	setcontrasenhia(contra);
}

void GenPass::RandomPass(int lenght) {
	static const char alphanum[] = "1234567890!#$%&*+@~_ABCDEFGHIJKLNMOPQRSTUVWXYZ-abcdefghijklmnopqrstuvwxyz;
	int string_lenght = sizeof(alphanum);
	int tam;
	srand(time(0));
	cout << "Ingresa el tamano de la contrasena: ";
	fflush(stdin);
	cin >> tam;
	cout << "Contrasena generada: ";
	for (int i = 0; i < lenght; i++) {
		cout << alphanum[rand() % string_lenght]
	}
}