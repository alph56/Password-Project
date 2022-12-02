#include<iostream>
#include"GenPass.h"
#include<windows.h>
#include<stdlib.h>

using namespace std;

int main() {

	GenPass Pass;
	string contrasenhia;
	int tam;

	cout << "Manual password function" << endl;
	cout << "Ingrese su contrasenhia: ";
	cin >> contrasenhia;
	fflush(stdin);
	Pass.Manual(contrasenhia);
	cout << "\nTu contrasena es: " << Pass.getcontrasenhia()<<endl;
	system("pause");
	cout << "\nRandom generator function" << endl;
	cout << "Ingresa el tamanhio de tu contrasena: ";
	fflush(stdin);
	cin >> tam;
	Pass.RandomPass(tam);
	cout << "\nTu contrasenhia es: " << Pass.getcontrasenhia() << endl;

	return 0;
}