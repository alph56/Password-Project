#ifndef PASSWORD_H
#define PASSWORD_H
#include<iostream>

using namespace std;

class GenPass {
private:
	string contrasenhia;
public:

	GenPass();
	void setcontrasenhia(string);
	string getcontrasenhia(void);

	void RandomPass(int);
  void ManualPass(string);
	void escribir(void);
  void leer(void);
};

#endif