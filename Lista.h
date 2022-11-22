#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
#include <iostream>
using namespace std;

class Lista{
public:
Lista();
Lista(Nodo*nextPos);
Nodo*head;
Nodo *tail;
void Append(Credencial);
};

#endif//LISTA_H