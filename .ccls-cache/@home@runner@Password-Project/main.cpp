#include <iostream>
using namespace std;

int main() {
int opcion;
int c;
int sit;
int contra;
int usu;
  
cout<<"----Bienvenido----"<<endl;
cout<<"Que desea hacer"<<endl;  
cout<<"Crear usuario y contraseña de un nuevo sitio"<<endl;
cout<<"Ver todos los sitios"<<endl;
cout<<"Ver usuario y contraseña de un sitio en especifico "
<<endl;
cout<<"Eliminar contraseña"<<endl;
cout<<"Modificar contraseñas"<<endl;  
switch (opcion)  {
    case 1:

      cout<<"sitio"<<endl;
        cin>>sit;
      
      cout<<"usuario"<<endl;
        cin>>usu;
      
      cout<<"crear contraseña nueva"<<endl;
      cout<<"generar contraseña nueva"<<endl;
      switch(c)
      {
        case 1:
      cout<<"contraseña"<<endl;
        cin>>contra;
        break;
        case 2:
        cout<<"generando contraseña"<<endl;
        break;
        default:
        cout<<"Error,Esa no es una opcion valida"<<endl;
      }
        break;

    case 2:
        cout<<"Estos son los sitios"<<endl;
      
        break;
    case 3:
        cout<<"Estos son los usiarios y contraseñas";
        break;
  case 4:

  break;
        
    default:
  cout<<"Error, Esa no es una opcion valida"<<endl;
  break;
  }
}