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

void Lista::AppendL(Credencial c1){
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

/*void Lista::LeerFile(void){
  ofstream fp("my_file.txt", ios::out | ios::binary);
  ifstream fpleer("my_file.txt", ios::in | ios::binary);
  if (!fp) {
      cout << "File not created!"<<endl;
      exit(1);
      }
  else{
    if(!head)
      cout<<"Lista vacia"<<endl;
    else{
      char *buf;
      Credencial help;
      Nodo*aux=head;
      while(!fp.eof() and aux){
        //SIZE1
        help.dominio=aux->dato.dominio;
        int size1=(help.dominio.size());
        //SIZE2
        help.SetUsuario(aux->dato.Getusuario());
        int size2=(help.Getusuario().size());
        //SIZE3
        help.Setpassword(aux->dato.Getpassword());
        int size3=(help.Getpassword().size());
        
        fpleer.read(reinterpret_cast<char *>(&size1), sizeof(int));
        buf = new char[size1];
        fpleer.read( buf, size1);
        help.dominio= "";
        help.dominio.append(buf, size1);
       } 
     }
   }
}*

void Lista::BuscarFile(string busquedab){
  ofstream fp;
  ifstream fpleer;
  if (!fp) {
      cout << "File not created!"<<endl;
      exit(1);
      }
  else{
    char *buf;
    Credencial help;
    Nodo*aux=head;
    while(!fp.eof()){
        //SIZE1
        help.dominio=aux->dato.dominio;
        int size1=(help.dominio.size());
        //SIZE2
        help.SetUsuario(aux->dato.Getusuario());
        int size2=(help.Getusuario().size());
        //SIZE3
        help.Setpassword(aux->dato.Getpassword());
        int size3=(help.Getpassword().size());
    }
  }
  fp.close();
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