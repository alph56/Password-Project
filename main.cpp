#include <iostream>
#include<locale.h>
#include"Lista.h"
//#include"GenPass.h"
using namespace std;

int main() {
  //Idioma:Español
  setlocale(LC_CTYPE, "Spanish");
  //OBJETOS
  //GenPass*mainpass=new GenPass();
  Lista*list=new Lista();
  string contra,comparar;
  //OPCIONES DE SWITCH
  int opcion,anws,selection;
  
  
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
      cout<<"¿Qué tipo de contraseña quiere realizar?"<<endl;
      cout<<"1.-Generar una manualmente"<<endl;
      cout<<"2.-Generar una aleatoriamente"<<endl;
      cout<<"3.-Regresar"<<endl;
      cout<<"Inserte una opcion: ";
      cin>>anws;
      switch(anws){
        case 1:
          system("cls");
          //mainpass->Manual(contra);
          system("pause");
          break;
        case 2:
          system("cls");
          //mainpass->RandomPass(contra);
          system("pause");
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
      break;
    case 2:
      cout<<"Ingrese su contraseña:"<<endl;
      cout<<"---->: ";
      cin>>comparar;
      if(){
        cout<<"Bienvenido a el menú gestor"<<endl;
        do{
          cout<<"1.-Ver Sitios Agregados"<<endl;
          cout<<"2.-Ver Sitios con contraseña y usuario"<<endl;
          cout<<"6.-Salir del menú gestor"<<endl;
        }while(selection!=6);
        
      }
      else{
        cout<<"contraseña Incorrecta"<<endl;
      }*/
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
