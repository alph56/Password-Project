#include <iostream>
using namespace std;

int main() {
  //Idioma:Español
  setlocale(LC_CTYPE, "Spanish");
  int opcion;
  cout<<"----Bienvenido----"<<endl;
  do{
  cout<<"¿Qué desea hacer?"<<endl;
  cout<<"1.-Generar contraseña"<<endl;
  cout<<"2.-Ingresar al sistema"<<endl;
  cout<<"3.-Salir"<<endl;
  cout<<"Inserte una opcion: ";
  cin>>opcion;
  switch(opcion){
    case 1:
      break;
    case 2:
      break;
    case 3:
      system("cls");
      cout<<"--->Saliendo...."<<endl;
      break;
    default:
      system("cls");
      cout<<"Opción NO válida"<<endl;
      system("pause");
      break;
   }
  }while(opcion!=3);
  return 0;
}
