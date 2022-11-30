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
    fstream fp;
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

