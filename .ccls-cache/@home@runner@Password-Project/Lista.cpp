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
    ofstream fp;
    fp.open("my_file.txt", ios::out);
    if (!fp) {
      cout << "File not created!"<<endl;
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
}

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

void Lista::BuscarFile(string busquedab){
  if(!head)
    cout<<"Lista vacia"<<endl;
  else{
    ifstream leer;
    Nodo*aux=head;
    leer.open("my_file.txt");
     if (!leer) {
      cout << "File not created!"<<endl;
      }
    else {
      bool band=false;
      while(aux and !leer.eof() and band==false){
        leer>>aux->dato.dominio;
        if(aux->dato.dominio==busquedab){
          band=true;
          cout<<"Nombre del sitio encontrado!!!"<<endl;
          cout<<"Dominio: "<<aux->dato.dominio<<endl;
          cout<<"Usuario: ----"<<endl;
          cout<<"Password: ----\n"<<endl;
        }
        else{
          aux=aux->Next;
        }
      }
      if(band==false)
        cout<<"Dato No Encontrado!!!"<<endl;
    }
    leer.close();
  }
}


void Lista::BuscarList(string busqueda){
    if(!head)
        cout<<"Lista vacia"<<endl;
    else{
      Nodo*tmp=head;
      bool band=true;
      while(tmp and band){
        if(tmp->dato.dominio==busqueda){
          band=false;
          cout<<"Nombre del sitio encontrado!!!"<<endl;
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