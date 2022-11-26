#ifndef NODO_H
#define NODO_H
#include <iostream>
#include "Credencial.h"
using namespace std;

class Nodo{
   public:
   Nodo();
   Nodo(Credencial,Nodo*);
   Credencial dato;
   Nodo*Next;
};

#endif