#include <iostream>
#include <fstream>
#include <string.h>
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
      //cout << "File created successfully!\n";
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
  ofstream fp("my_file.txt", ios::out | ios::binary);
  ifstream fpleer("my_file.txt", ios::in | ios::binary);
  if (!fp) {
      cout << "File not created!"<<endl;
      exit(1);
      }
  else{
    char *buf;
    Credencial help;
    bool band=false;
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

      fpleer.read(reinterpret_cast<char *>(&size1), sizeof(int));
      buf = new char[size1];
      fpleer.read( buf, size1);
      help.dominio= "";
      help.dominio.append(buf, size1);

      fpleer.read(reinterpret_cast<char *>(&size2), sizeof(int));
      buf = new char[size2];
      fpleer.read( buf, size2);
      help.Getpassword()= "";
      help.Getpassword().append(buf, size2);

      fpleer.read(reinterpret_cast<char *>(&size3), sizeof(int));
      buf = new char[size3];
      fpleer.read( buf, size3);
      help.Getusuario()= "";
      help.Getusuario().append(buf, size3);

      fpleer>>help.dominio;
      if(busquedab==help.dominio){
        band=true;
        cout<<help.dominio<<endl;
        cout<<help.Getusuario();
        cout<<help.Getpassword();
      }
      else{
        aux=aux->Next;
      }
    }
    if(band==false){
        cout<<"Dato No encontrado"<<endl;
    }
  }
  fp.close();
}*/


void Lista::BuscarList(string busqueda){
    if(!head)
        cout<<"Lista vacia"<<endl;
    else{
      Nodo*tmp=head;
      bool band=true;
      Credencial help;
      char *buf;
      ifstream fpleer("my_file.txt", ios::in | ios::binary);
      ofstream fp("my_file.txt", ios::out | ios::binary);
      if (!fp) {
      cout << "File not created!"<<endl;
      exit(1);
      }
      else{
      while(tmp and band){
        //SIZE1
          help.dominio=tmp->dato.dominio;
          int size1=(help.dominio.size());
          //SIZE2
          help.SetUsuario(tmp->dato.Getusuario());
          int size2=(help.Getusuario().size());
          //SIZE3
          help.Setpassword(tmp->dato.Getpassword());
          int size3=(help.Getpassword().size());

         fpleer.read(reinterpret_cast<char *>(&size1), sizeof(int));
         buf = new char[size1];
         fpleer.read( buf, size1);
         help.dominio= "";
         help.dominio.append(buf, size1);

         fpleer.read(reinterpret_cast<char *>(&size2), sizeof(int));
         buf = new char[size2];
         fpleer.read( buf, size2);
         help.Getpassword()= "";
         help.Getpassword().append(buf, size2);

         fpleer.read(reinterpret_cast<char *>(&size3), sizeof(int));
         buf = new char[size3];
         fpleer.read( buf, size3);
         help.Getusuario()= "";
         help.Getusuario().append(buf, size3);
        
        if(tmp->dato.dominio==busqueda){
          band=false;
          cout<<"\nNombre del sitio encontrado!!!"<<endl;
          cout<<"Dominio: "<<tmp->dato.dominio<<endl;
          cout<<"Usuario: "<<help.Getusuario()<<endl;
          cout<<"Password: "<<help.Getpassword()<<endl;
        }
        else{
          tmp=tmp->Next;
        }
      }
      if(!tmp)
        cout<<"Dato No Encontrado!!!"<<endl;
    }
      Tofile();
  }
}

void Lista::Eliminar(string eliminar){
	if(!head)
        cout<<"Lista vacia"<<endl;
    else{
      Nodo *tmp=head;
      Nodo *tmpAnt;
      Credencial help;
      char *buf;
      bool band=true;
      ifstream fpleer("my_file.txt", ios::in | ios::binary);
      ofstream fp("my_file.txt", ios::out | ios::binary);
        while(tmp and band){
           //SIZE1
          help.dominio=tmp->dato.dominio;
          int size1=(help.dominio.size());
          //SIZE2
          help.SetUsuario(tmp->dato.Getusuario());
          int size2=(help.Getusuario().size());
          //SIZE3
          help.Setpassword(tmp->dato.Getpassword());
          int size3=(help.Getpassword().size());

         fpleer.read(reinterpret_cast<char *>(&size1), sizeof(int));
         buf = new char[size1];
         fpleer.read( buf, size1);
         help.dominio= "";
         help.dominio.append(buf, size1);

         fpleer.read(reinterpret_cast<char *>(&size2), sizeof(int));
         buf = new char[size2];
         fpleer.read( buf, size2);
         help.Getpassword()= "";
         help.Getpassword().append(buf, size2);

         fpleer.read(reinterpret_cast<char *>(&size3), sizeof(int));
         buf = new char[size3];
         fpleer.read( buf, size3);
         help.Getusuario()= "";
         help.Getusuario().append(buf, size3);
            if(tmp->dato.dominio==eliminar){
                band=false;
            }
            else{
                tmpAnt=tmp;
                tmp=tmp->Next;
            }
        }

    if (tmp==nullptr){
			cout<<"Dato No Encontrado"<<endl;
		}
		else if(tmp==head){
			head=head->Next;
			delete tmp;
		}
		else if(tmp->Next==nullptr){
			tmpAnt->Next=nullptr;
			delete tmp;
		}
		else{
			tmpAnt->Next=tmp->Next;
			delete tmp;
		}
      Tofile();
  }
}

void Lista::EliminarTodo(void){
  if(!head)
    cout<<"Lista vacía"<<endl;
  else{
    Nodo*tmp=head;
    Credencial help;
    char *buf;
    ifstream fpleer("my_file.txt", ios::in | ios::binary);
    ofstream fp("my_file.txt", ios::out | ios::binary);
    while(head){
         tmp=head;
         //SIZE1
          help.dominio=tmp->dato.dominio;
          int size1=(help.dominio.size());
          //SIZE2
          help.SetUsuario(tmp->dato.Getusuario());
          int size2=(help.Getusuario().size());
          //SIZE3
          help.Setpassword(tmp->dato.Getpassword());
          int size3=(help.Getpassword().size());

         fpleer.read(reinterpret_cast<char *>(&size1), sizeof(int));
         buf = new char[size1];
         fpleer.read( buf, size1);
         help.dominio= "";
         help.dominio.append(buf, size1);

         fpleer.read(reinterpret_cast<char *>(&size2), sizeof(int));
         buf = new char[size2];
         fpleer.read( buf, size2);
         help.Getpassword()= "";
         help.Getpassword().append(buf, size2);

         fpleer.read(reinterpret_cast<char *>(&size3), sizeof(int));
         buf = new char[size3];
         fpleer.read( buf, size3);
         help.Getusuario()= "";
         help.Getusuario().append(buf, size3);
      
         head=head->Next;
         delete tmp;
    }
    cout<<"Lista eliminada con exito"<<endl;
    Tofile();
  }
}

void Lista::ModificarDom(string busqueda,Credencial change){
  if(!head)
    cout<<"Lista vacía"<<endl;
  else{
    Nodo*tmp=head;
    bool band=true;
    Credencial help;
    char *buf;
    ifstream fpleer("my_file.txt", ios::in | ios::binary);
    ofstream fp("my_file.txt", ios::out | ios::binary);
    
    while(tmp and band){
          //SIZE1
          help.dominio=tmp->dato.dominio;
          int size1=(help.dominio.size());
          //SIZE2
          help.SetUsuario(tmp->dato.Getusuario());
          int size2=(help.Getusuario().size());
          //SIZE3
          help.Setpassword(tmp->dato.Getpassword());
          int size3=(help.Getpassword().size());

         fpleer.read(reinterpret_cast<char *>(&size1), sizeof(int));
         buf = new char[size1];
         fpleer.read( buf, size1);
         help.dominio= "";
         help.dominio.append(buf, size1);

         fpleer.read(reinterpret_cast<char *>(&size2), sizeof(int));
         buf = new char[size2];
         fpleer.read( buf, size2);
         help.Getpassword()= "";
         help.Getpassword().append(buf, size2);

         fpleer.read(reinterpret_cast<char *>(&size3), sizeof(int));
         buf = new char[size3];
         fpleer.read( buf, size3);
         help.Getusuario()= "";
         help.Getusuario().append(buf, size3);

      if(tmp->dato.dominio==busqueda){
        band=false;
        cout<<"\nDato Encontrado!!\n"<<endl;
        cout<<"Dominio: "<<tmp->dato.dominio<<endl;
        tmp->dato.dominio=change.dominio;
        cout<<"\nDato Modificado!!\n"<<endl;
         cout<<"---->Dominio: "<<tmp->dato.dominio<<endl;
      }
      else{
        tmp=tmp->Next;
      }
    }
    if(!tmp){
     cout<<"\nEse Titulo NO Existe!!\n"<<endl;      
    }
    Tofile();
  }
}

void Lista::ModificarUsuar(string busqueda,Credencial change){
  if(!head)
    cout<<"Lista vacía"<<endl;
  else{
    Nodo*tmp=head;
    bool band=true;
    Credencial help;
    char *buf;
    ifstream fpleer("my_file.txt", ios::in | ios::binary);
    ofstream fp("my_file.txt", ios::out | ios::binary);
    while(tmp and band){
          //SIZE1
          help.dominio=tmp->dato.dominio;
          int size1=(help.dominio.size());
          //SIZE2
          help.SetUsuario(tmp->dato.Getusuario());
          int size2=(help.Getusuario().size());
          //SIZE3
          help.Setpassword(tmp->dato.Getpassword());
          int size3=(help.Getpassword().size());

         fpleer.read(reinterpret_cast<char *>(&size1), sizeof(int));
         buf = new char[size1];
         fpleer.read( buf, size1);
         help.dominio= "";
         help.dominio.append(buf, size1);

         fpleer.read(reinterpret_cast<char *>(&size2), sizeof(int));
         buf = new char[size2];
         fpleer.read( buf, size2);
         help.Getpassword()= "";
         help.Getpassword().append(buf, size2);

         fpleer.read(reinterpret_cast<char *>(&size3), sizeof(int));
         buf = new char[size3];
         fpleer.read( buf, size3);
         help.Getusuario()= "";
         help.Getusuario().append(buf, size3);

      if(tmp->dato.dominio==busqueda){
        band=false;
        cout<<"\nDato Encontrado!!\n"<<endl;
        cout<<"Dominio: "<<tmp->dato.dominio<<endl;
        cout<<"Usuario: "<<tmp->dato.Getusuario()<<endl;
        tmp->dato.SetUsuario(change.Getusuario());
        cout<<"\nDato Modificado!!\n"<<endl;
        cout<<"Dominio: "<<tmp->dato.dominio<<endl;
        cout<<"---->Usuario: "<<tmp->dato.Getusuario()<<endl;
      }
      else{
        tmp=tmp->Next;
      }
    }
     if(!tmp){
     cout<<"\nEse Titulo NO Existe!!\n"<<endl;      
    }
    Tofile();
  }
}

void Lista::ModificarPass(string busqueda,Credencial change){
  if(!head)
    cout<<"Lista vacía"<<endl;
  else{
    Nodo*tmp=head;
    bool band=true;
    Credencial help;
    char *buf;
    ifstream fpleer("my_file.txt", ios::in | ios::binary);
    ofstream fp("my_file.txt", ios::out | ios::binary);
    while(tmp and band){
          //SIZE1
          help.dominio=tmp->dato.dominio;
          int size1=(help.dominio.size());
          //SIZE2
          help.SetUsuario(tmp->dato.Getusuario());
          int size2=(help.Getusuario().size());
          //SIZE3
          help.Setpassword(tmp->dato.Getpassword());
          int size3=(help.Getpassword().size());

         fpleer.read(reinterpret_cast<char *>(&size1), sizeof(int));
         buf = new char[size1];
         fpleer.read( buf, size1);
         help.dominio= "";
         help.dominio.append(buf, size1);

         fpleer.read(reinterpret_cast<char *>(&size2), sizeof(int));
         buf = new char[size2];
         fpleer.read( buf, size2);
         help.Getpassword()= "";
         help.Getpassword().append(buf, size2);

         fpleer.read(reinterpret_cast<char *>(&size3), sizeof(int));
         buf = new char[size3];
         fpleer.read( buf, size3);
         help.Getusuario()= "";
         help.Getusuario().append(buf, size3);

      if(tmp->dato.dominio==busqueda){
        band=false;
        cout<<"\nDato Encontrado!!\n"<<endl;
        cout<<"Dominio: "<<tmp->dato.dominio<<endl;
        tmp->dato.Setpassword(change.Getpassword());
        cout<<"\nDato Modificado!!\n"<<endl;
        cout<<"Dominio: "<<tmp->dato.dominio<<endl;
        cout<<"Contraseña: "<<tmp->dato.Getpassword();
      }
      else{
        tmp=tmp->Next;
      }
    }
     if(!tmp){
     cout<<"\nEse Titulo NO Existe!!\n"<<endl;      
    }
    Tofile();
  }
}

/*void Lista::Encrypt(GenPass p1,Credencial c1){
}*/
