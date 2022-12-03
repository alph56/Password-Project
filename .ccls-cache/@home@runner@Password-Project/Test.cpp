#include<iostream>
#include<stdlib.h>
#include"GenPass.h"
#include"Lista.h"

using namespace std;

int main() {

	GenPass Pass;
	string mainpassword,comprobar;
	int tam;

	cout << "Manual password function" << endl;
	cout << "Ingrese su contrasenhia: ";
	cin >> mainpassword;
	fflush(stdin);
	Pass.ManualPass(mainpassword);
	cout << "\nTu contrasena es: " << Pass.getcontrasenhia()<<endl;
	cout<<"\n"<<endl;
	//cout << "\nRandom generator function" << endl;
	cout << "Ingresa la contraseña: ";
	fflush(stdin);
	cin >>comprobar;
  cout<<Pass.Verificador(comprobar);
	//Pass.RandomPass(tam);
	//cout << "\nTu contrasenhia es: " << Pass.getcontrasenhia() << endl;

	return 0;
}