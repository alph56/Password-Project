#include <iostream>
#include "Lista.h"
#include "GenPass.h"
using namespace std;

int main() {
Lista*list=new Lista();
  string busqueda;
  Credencial c1,change;
  GenPass Pass;
	string mainpassword,temporal;
  
  cout << "Manual password function" << endl;
	cout << "Ingrese su contrasenhia: ";
	cin >> mainpassword;
	fflush(stdin);
	Pass.ManualPass(mainpassword);
  cout << "\nTu contrasena es: " << Pass.getcontrasenhia()<<endl;
	cout<<"\n"<<endl;
  
  c1.dominio="www.google.com";
  string a="alph56";
  string b="Hola987";
  c1.SetUsuario(a);
  //list->EncryptPassword();
  c1.Setpassword(list->EncryptPassword(Pass.getcontrasenhia(),b));
  list->AppendL(c1);

  c1.dominio="www.epicgames.com";
  string c="newplayer01";
  string d="contrasena132";
  c1.Setpassword(d);
  c1.SetUsuario(c);
  list->AppendL(c1);
  list->MostrarTodoP();
  list->Tofile();
  string f="www.google.com";
  //list->BuscarList(f);
  //list->Eliminar(f);
  //list->MostrarTodoP();

  /*change.dominio="www.yahoo.com";
  busqueda="www.google.com";
  list->ModificarDom(busqueda,change);
  list->MostrarTodoP();*/

}
