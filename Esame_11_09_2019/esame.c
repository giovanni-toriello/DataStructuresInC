#include <stdio.h>
#include "esame.h"
#include "lista.h"

lista cancFinoItem(lista l,item e){
    if(emptyList(l)){
        return NULL;
    }
    if(e==NULL){
        return NULL;
    }
    int elem = posItem(l,e);
    if(elem <0){
        return NULL;
    }
    int i = 0;
    while(i<elem){
        output_item(getFirst(l));
        printf("\n");
        l = tailList(l);
        i++;
    }
    return l;
}

lista fondiDaItem(lista l1,lista l2, item e){
    if(emptyList(l1) || emptyList(l2)){
        return NULL;
    }
    if(e==NULL){
        return NULL;
    }
    lista l3 = newList();
    l1 = cancFinoItem(l1,e);
    l2 = cancFinoItem(l2,e);
    while(!emptyList(l1) || !emptyList(l2)){
        item uno = getFirst(l1);
        item due = getFirst(l2);
        if(eq(uno,due)){
            l3 = consList(uno,l3);
        }
        l1 = tailList(l1);
        l2 = tailList(l2);
    }
}

