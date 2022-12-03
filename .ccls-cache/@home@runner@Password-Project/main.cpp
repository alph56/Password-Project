#include <iostream>
#include<locale.h>
#include<cstdlib>
#include"Lista.h"
#include"GenPass.h"
using namespace std;

int main() {
  //Idioma:Español
  setlocale(LC_CTYPE, "Spanish");
  //OBJETOS
  GenPass Pass;
  Lista*list=new Lista();
  Credencial c1,change;
  string mainpassword,comparar,busqueda,usuarc,passc,eliminar;
  int lenght;
  //OPCIONES DE SWITCH
  int opcion,anws,selection;
  
  
  cout<<"----Bienvenido----"<<endl;
  do{
  system("cls");
  cout<<"¿Qué desea hacer?"<<endl;
  cout<<"1.-Generar contraseña"<<endl;
  cout<<"2.-Ingresar al sistema"<<endl;
  cout<<"3.-Salir"<<endl;
  cout<<"Inserte una opcion: ";
  cin>>opcion;
  fflush(stdin);
  switch(opcion){
    case 1:
      system("cls");
      cout<<"¿Qué tipo de contraseña quiere realizar?"<<endl;
      cout<<"1.-Generar una manualmente"<<endl;
      cout<<"2.-Generar una aleatoriamente"<<endl;
      cout<<"3.-Regresar"<<endl;
      cout<<"Inserte una opcion: ";
      cin>>anws;
      fflush(stdin);
      switch(anws){
        case 1:
          system("cls");
          cout<<"Bienvenido a el menú generador de contraseñas"<<endl;
          cout<<"Ingrese una nueva contraseña"<<endl;
          cin>>mainpassword;
          fflush(stdin);
          Pass.ManualPass(mainpassword);
          cout<<"Su contraseña quedó definida como: "<<Pass.getcontrasenhia()<<endl;
          system("pause");
          break;
        case 2:
          system("cls");
          cout << "Ingresa el tamaño de tu contrasena: ";
          fflush(stdin);
          cin >> lenght;
          Pass.RandomPass(lenght);
          cout<<"Su contraseña quedó definida como: "<<Pass.getcontrasenhia()<<endl;
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
      fflush(stdin);
      if(Pass.Verificador(comparar)==1){
        do{
          cout<<"Bienvenido a el menú gestor"<<endl;
          cout<<"1.-Agregar Sitio nuevo"<<endl;
          cout<<"2.-Ver Todos los sitios Agregados"<<endl;
          cout<<"3.-Ver Todos los sitios con contraseña y usuario"<<endl;
          cout<<"4.-Buscar nombre de Sitio"<<endl;
          cout<<"5.-Modificar contraseña de Sitio"<<endl;
          cout<<"6.-Modificar usuario de Sitio"<<endl;
          cout<<"7.-Modificar nombre de Sitio"<<endl;
          cout<<"8.-Eliminar Sitio"<<endl;
          cout<<"9.-Eliminar Todo"<<endl;
          cout<<"10.-Salir del menú gestor"<<endl;
          cout<<"Inserte una opcion: ";
          cin>>selection;
          fflush(stdin);
          switch(selection){
            case 1:
              system("cls");
              cout<<"Inserte el nombre del sitio: ";
              cin>>c1.dominio;
              fflush(stdin);
              cout<<"Inserte su nombre de usuario de ese sitio web: ";
              cin>>usuarc;
              c1.SetUsuario(usuarc);
              fflush(stdin);
              cout<<"Inserte su contraseña de ese sitio web: ";
              cin>>passc;
              c1.Setpassword(passc);
              fflush(stdin);
              list->AppendL(c1);
              system("pause");
              break;
            case 2:
              cout<<"Por cuestiones de Privacidad Usuario y Contraseña se mantienen ocultos"<<endl;
              list->MostrarTodoP();
              break;
            case 3:
              system("cls");
              cout<<"Ingrese su contraseña:"<<endl;
              cout<<"---->: ";
              cin>>comparar;
              fflush(stdin);
              if(Pass.Verificador(comparar)==1){
                system("cls");
                list->MostrarTodo();
                system("pause");
              }
              else{
                system("cls");
                cout<<"contraseña Incorrecta"<<endl;
                system("pause");
              }
              break;
            case 4:
                system("cls");
                cout<<"Ingrese el nombre del sitio que desee buscar: ";
                cin>>busqueda;
                fflush(stdin);
                list->BuscarList(busqueda);
                system("pause");
              break;
            case 7:
              system("cls");
              cout<<"Ingrese el nombre del sitio a modificar: ";
              cin>>busqueda;
              fflush(stdin);
              cout<<"Ingrese el nuevo nombre del Sitio: ";
              cin>>change.dominio;
              fflush(stdin);
              list->ModificarDom(busqueda,change);
              system("pause");
              break;
            case 6:
              system("cls");
              cout<<"Ingrese el nombre del sitio donde se encuentre el usuario a modificar: ";
              cin>>busqueda;
              fflush(stdin);
              cout<<"Ingrese el nuevo nombre de usuario: ";
              cin>>usuarc;
              change.SetUsuario(usuarc);
              fflush(stdin);
              list->ModificarUsuar(busqueda,change);
              system("pause");
              break;
            case 5:
              system("cls");
              cout<<"Ingrese el nombre del sitio donde se encuentre la ocntraseña a modificar: ";
              cin>>busqueda;
              fflush(stdin);
              cout<<"Ingrese la nueva contraseña: ";
              cin>>passc;
              change.Setpassword(passc);
              fflush(stdin);
              list->ModificarPass(busqueda,change);
              system("pause");
              break;
            case 9:
              system("cls");
              int seguro;
              cout<<"\t----Eliminar Toda la Lista----"<<endl;
              cout<<"->¿Seguro(a) que quieres eliminar todo?"<<endl;
              cout<<"1.-Sí\t2.-No"<<endl;
              cout<<"Inserte su respuesta: ";
              fflush(stdin);
              cin>>seguro;
              switch(seguro){
                case 1:
                  system("cls");
                  cout<<"Bueno....si tú lo dices"<<endl;
                  list->EliminarTodo();
                  system("pause");
                  break;
                case 2:
                  system("cls");
                  cout<<"Ya ves, piénsalo bien"<<endl;
                  system("pause");
                  break;
                default:
                  system("cls");
                  cout<<"Opción NO válida"<<endl;
                  system("pause");
                  break;
              }
              break;
            case 8:
              system("cls");
              cout<<"Ingrese el nombre del sitio a eliminar: ";
              cin>>eliminar;
              fflush(stdin);
              list->Eliminar(eliminar);
              system("pause");
              break;
            case 10:
              system("cls");
              cout<<"--->Regresando al menú de inicio...."<<endl;
              break;
            default:
              system("cls");
              cout<<"Opción NO válida"<<endl;
              system("pause");
              break;
          }
        }while(selection!=10);
      }
      else{
        system("cls");
        cout<<"contraseña Incorrecta"<<endl;
        system("pause");
      }
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
