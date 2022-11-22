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