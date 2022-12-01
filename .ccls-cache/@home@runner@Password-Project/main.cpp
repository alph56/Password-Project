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

  c1.dominio="www.epicgames.com";
  string c="newplayer01";
  string d="contrasena132";
  c1.Setpassword(d);
  c1.SetUsuario(c);
  list->Append(c1);
  list->MostrarTodoP();
  list->Tofile();
  string f="www.google.com";
  list->BuscarList(f);
}
