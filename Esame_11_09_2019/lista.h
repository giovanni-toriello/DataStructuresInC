#include <stdio.h>
#include <stdlib.h>
#include "item.h"
typedef struct node *lista;

lista newList();
int emptyList(lista l);
lista tailList(lista l);
lista consList(item val, lista l);
item getFirst (lista l);
int sizeList(lista l);
int posItem(lista l, item val);
lista reverseList(lista l);
lista removeItem(lista l, item val);
item getItem(lista l, int i);
lista insertList(lista l, item val,int i);
lista removeList(lista l, int);
