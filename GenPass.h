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

	void Manual(string);
	void RandomPass(int);
};

#endif