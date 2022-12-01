#ifndef PASSWORD_H
#define PASSWORD_H
#include<iostream>

using namespace std;

class GenPass {
private:
	string password;
public:

	GenPass();
	void setpassword(string);
	string getpassword(void);

	void Manual(string);
};

#endif