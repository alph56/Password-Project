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
  Nodo*tmp;
  fstream fp;
	fp.open("my_file.txt", ios::out);
	if (!fp) {
		cout << "File not created!";
	}
	else {
		cout << "File created successfully!";
		fp <<dato.dominio<<"/"<<dato.Getpassword<<"/"<<dato.Getusuario;
		fp.close();
	}
}