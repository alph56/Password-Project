#include "Nodo.h"

Nodo::Nodo(Credencial dato,Nodo*Next){
  this->dato=dato;
  this->Next=Next;
}

Nodo::Nodo(){
  dato.dominio=" ";
  dato.SetUsuario(" ");
  dato.SetUsuario(" ");
  Next=nullptr;
}