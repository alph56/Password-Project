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

void Append(Credencial);
void Tofile(void);
void BuscarFile(string);
void BuscarList(string);
void MostrarTodo(void);
void MostrarTodoP(void);

};

#endif//LISTA_H