#include "GenPass.h"
#include <stdlib.h>

GenPass::GenPass() {
	password = "Unknown";
}

void GenPass::setpassword(string password) {
	this->password = password;
}
string GenPass::getpassword(void) {
	return password;
}

void GenPass::Manual(string password) {
	string password;
	cout << "Ingrese su nueva contrasena: ";
	fflush(stdin);
	cin >> password;
	setpassword(password);
}
