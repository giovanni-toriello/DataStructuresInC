#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct node{
    item value;
    struct node *next;
};
lista newList(){
    return NULL;
}
int emptyList(lista l){
    return l == NULL;
}
lista tailList(lista l){
    lista temp;
    if(l!=NULL){
        temp = l->next;
    }
    else{
        temp = NULL;
    }
    return temp;
}
lista consList(item val, lista l){
    struct node *nuovo;
    nuovo = malloc(sizeof(struct node));
    if(nuovo!=NULL){
        nuovo->value = val;
        nuovo->next = l;
        l = nuovo;
    }
    return l;
}
item getFirst (lista l){
    item lib;
    if(l!=NULL){
        lib=l->value;
    }
    else lib = NULL;
    return lib;
}
int sizeList(lista l){
    int size = 0;
    while(!emptyList(l)){
        size++;
        l = tailList(l);
    }
    return size;
}
int posItem (lista l, item val)
{
    int pos =0; // contatore di posizione
    int found =0;

    while (!emptyList(l) && !found) {
        if (eq(getFirst(l), val))
            found =1;
        else {
            pos++; // incrementa il contatore di posizione
            l = tailList(l);  // continuiamo la visita degli elementi della lista
        }
    }

    if(!found)
        pos = -1;  // se non trovato restituiamo come posizione -1

    return pos;
}
lista reverseList(lista l){
    lista s;
    item val;

    s = newList();
    while(!emptyList(l)){
        val = getFirst(l);
        s = consList(val,s);
        l = tailList(l);
    }
    return s;
}
lista removeItem(lista l, item val);
item getItem(lista l, int pos){
    item lib;
    int i = 0;
    while(i<pos && !emptyList(l)){
        i++;
        l = tailList(l);
    }
    if(!emptyList(l)){
        lib = getFirst(l);
    }else lib = NULL;
    return lib;

}
lista insertList(lista l, item val,int i);
lista removeList(lista l, int);

