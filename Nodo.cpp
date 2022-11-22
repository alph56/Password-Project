#include "Nodo.h"

Nodo::Nodo(Credencial dato,Nodo*Next){
  this->dato=dato;
  this->Next=Next;
}

Nodo::Nodo(){
  dato.dominio=" ";
  Next=nullptr;
}