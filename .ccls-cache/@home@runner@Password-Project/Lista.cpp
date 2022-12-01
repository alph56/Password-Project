#include <iostream>
#include <fstream>
#include "Lista.h"
using namespace std;

Lista::Lista(Nodo*nextPos){
  this->head=nextPos;
}

Lista::Lista(){
  head=nullptr;
}

void Lista::Append(Credencial c1){
  Nodo*aux=new Nodo(c1,nullptr);
  if(!head){
    head=aux;
  }
  else{
    Nodo*tmp=head;
    while(tmp->Next!=nullptr){
     tmp=tmp->Next; 
    }
    tmp->Next=aux;
  }
  
}

void Lista::Tofile(void){
  if(!head)
    cout<<"No hay elementos para agregar en archivo txt"<<endl;
  else{
    Nodo*aux=head;
    Credencial help;
    char*buf;
    ofstream fp("my_file.txt", ios::out | ios::binary);
    if (!fp) {
      cout << "File not created!"<<endl;
      exit(1);
      }
    else {
      cout << "File created successfully!\n";
      while(aux){
        //SIZE1
        help.dominio=aux->dato.dominio;
        int size1=(help.dominio.size());
        //SIZE2
        help.SetUsuario(aux->dato.Getusuario());
        int size2=(help.Getusuario().size());
        //SIZE3
        help.Setpassword(aux->dato.Getpassword());
        int size3=(help.Getpassword().size());

        //WRITING ON TXT
        //SIZE1
        fp.write(reinterpret_cast<char *>(&size1), sizeof(int));
        fp.write(help.dominio.c_str(), size1);
        //SIZE2
        fp.write(reinterpret_cast<char *>(&size2), sizeof(int));
        fp.write(help.Getusuario().c_str(), size2);
        //SIZE3
        fp.write(reinterpret_cast<char *>(&size3), sizeof(int));
        fp.write(help.Getpassword().c_str(), size3);
        //CAMBIO DE NODO
        aux=aux->Next;
        }
     }
     fp.flush();
     fp.close();
  }
}

/*void Lista::Tofile(void){
  if(!head)
    cout<<"No hay elementos para agregar en archivo txt"<<endl;
  else{
    Nodo*aux=head;
    ofstream fp;
    //char *buf;
    fp.open("my_file.txt", ios::out|ios::binary);
    if (!fp) {
      cout << "File not created!"<<endl;
      exit(1);
      }
    else {
      cout << "File created successfully!\n";
      while(aux){
        fp <<aux->dato.dominio<<"-"<<aux->dato.Getpassword()<<"-"<<aux->dato.Getusuario()<<"-";
        aux=aux->Next;
        }
     }
     fp.close();
  }
}*/

void Lista::MostrarTodo(void){
  if(!head)
    cout<<"Lista vacia"<<endl;
  else{
    Nodo*aux=head;
    while(aux!=nullptr){
      cout<<aux->dato.dominio<<"-"<<aux->dato.Getpassword()<<"-"<<aux->dato.Getusuario()<<"-";
      aux=aux->Next;
    }
  }
}

void Lista::MostrarTodoP(void){
  if(!head)
    cout<<"Lista vacia"<<endl;
  else{
    Nodo*aux=head;
    while(aux){
      cout<<"Dominio: "<<aux->dato.dominio<<"\nUsuario: ----"<<"\nPassword: ----\n"<<endl;
      aux=aux->Next;
    }
  }
}

/*void Lista::BuscarFile(string busquedab){
  if(!head)
    cout<<"Lista vacia"<<endl;
  else{
    ifstream fp;
    Nodo*aux=head;
    fp.open("my_file.txt");
    fp>>aux->dato.dominio;
     if (!fp) {
      cout << "File not created!"<<endl;
      }
    else {
      bool band=false;
      while(!fp.eof() and band==false){
      while(aux){
        fp>>aux->dato.dominio;
        if(aux->dato.dominio==busquedab){
          band=true;
          cout<<"Nombre del sitio encontrado!!!"<<endl;
          cout<<"Dominio: "<<aux->dato.dominio<<endl;
          cout<<"Usuario: ----"<<endl;
          cout<<"Password: ----\n"<<endl;
          fp>>aux->dato.dominio;
        }
        else{
          aux=aux->Next;
        }
      }
    }
      if(band==false)
        cout<<"Dato No Encontrado!!!"<<endl;
    }
    fp.close();
  }
}*/


void Lista::BuscarList(string busqueda){
    if(!head)
        cout<<"Lista vacia"<<endl;
    else{
      Nodo*tmp=head;
      bool band=true;
      while(tmp and band){
        if(tmp->dato.dominio==busqueda){
          band=false;
          cout<<"\nNombre del sitio encontrado!!!"<<endl;
          cout<<"Dominio: "<<tmp->dato.dominio<<endl;
          cout<<"Usuario: ----"<<endl;
          cout<<"Password: ----\n"<<endl;
        }
        else{
          tmp=tmp->Next;
        }
      }
      if(!tmp)
        cout<<"Dato No Encontrado!!!"<<endl;
    } 
}