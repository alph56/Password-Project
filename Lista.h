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

void AppendL(Credencial);
void Tofile(void);
void LeerFile(void);
void BuscarFile(string);
void BuscarList(string);
void Eliminar(string);
void EliminarTodo(void);
void MostrarTodo(void);
void MostrarTodoP(void);
void Encrypt(Credencial);
};

#endif//LISTA_H
