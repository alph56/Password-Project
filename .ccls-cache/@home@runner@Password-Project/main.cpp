#include <iostream>
#include "Lista.h"
using namespace std;

int main() {
  Lista*list=new Lista();
  Credencial c1;
  c1.dominio="www.google.com";
  string a="alph56";
  string b="Hola987";
  c1.Setpassword(b);
  c1.SetUsuario(a);
  list->Append(c1);
  list->MostrarTodo();
  list->Tofile(c1);
  
  cout << "Hello World!\n";
}
