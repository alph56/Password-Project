#include <iostream>
#include <fstream>
#include "Lista.h"
using namespace std;

Lista::Lista(Nodo*nextPos){
  this->head=nextPos;
  this->tail=nullptr;
}

Lista::Lista(){
  head=nullptr;
  tail=nullptr;
}

void Lista::Append(Credencial c1){
  Nodo*aux=new Nodo(c1,nullptr);
  if(!head){
    head=aux;
  }
  else{
    Nodo*tmp=head;
    while(tmp->Next!=nullptr)
      tmp=tmp->Next;
    tmp->Next=tmp;
  }
  
}

void Lista::Tofile(Credencial c1){
  Nodo*aux=head;
  fstream fp;
	fp.open("my_file.txt", ios::out);
	if (!fp) {
		cout << "File not created!";
	}
	else {
    cout << "File created successfully!";
    while(aux){
		fp <<aux->dato.dominio<<"-"<<aux->dato.Getpassword()<<"-"<<aux->dato.Getusuario();
		fp.close();
	  } 
  }
}

void Lista::MostrarTodo(void){
  if(!head)
    cout<<"Lista vacia"<<endl;
  else{
    Nodo*aux=head;
    while(aux){
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
      cout<<"Dominio: "<<aux->dato.dominio<<"\nUsuario: ----"<<"\nPassword: ----"<<endl;
      aux=aux->Next;
    }
  }
}