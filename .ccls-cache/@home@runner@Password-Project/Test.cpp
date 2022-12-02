#include<iostream>
#include"GenPass.h"
#include<windows.h>

using namespace std;

int main() {

	GenPass Pass;

	cout << "Manual password function" << endl;
	Pass.Manual(string contrasenhia);
	cout << "\nTu contrasena es: " << Pass.getcontrasenhia();
	system("pause");
	cout << "\nRandom generator function" << endl;
	Pass.RandomPass(int tam);

	return 0;
}