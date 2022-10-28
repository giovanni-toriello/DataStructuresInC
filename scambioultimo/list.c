//
// Created by nucle on 12/10/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"

struct node {
    item value;
    struct node *next;
};


list newList(void) {
    return NULL;
}

int emptyList(list l) {
    return l == NULL;
}


list consList(item val, list l) {
    struct node *nuovo;
    nuovo = malloc(sizeof(struct node));
    if (nuovo != NULL) {
        nuovo->value = val;
        nuovo->next = l;
        l = nuovo;
    }
    return l;
}

list tailList(list l)
{
    list temp;
    if (l != NULL)
        temp = l->next;
    else
        temp = NULL;
    return temp;
}

// uso tipico dell’operatore:
//   L = tailList(L);
item getFirst (list l)
{
    item e;
    if(l != NULL)
        e = l->value;
    else
        e = NULL;
    return e;
}
int sizeList (list l)
{
    int n=0;
    while (!emptyList(l)) // finché non raggiungiamo la fine della lista
    {
        n++;    		// il primo elemento contribuisce al conteggio
        l = tailList(l);  	// continuiamo la visita degli elementi successivi
    }
    return n;
}
int posItem (list l, item val)
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
item getItem (list l, int pos)
{
    item e;
    int i =0;
    // prima scorriamo la lista fino alla posizione pos … se esiste
    while (i < pos && !emptyList(l)) {
        i++;
        l = tailList(l);
    }

    if (!emptyList(l)) // se la lista ha almeno pos+1 elementi
        e = getFirst(l);  // elemento di posizione pos
    else e = NULL;

    return e;
}
list reverseList (list l)
{
    list rev;
    item val;

    rev = newList();

    while (!emptyList(l)) {
        val = getFirst(l);
        rev = consList(val, rev);
        l = tailList(l);
    }

    return rev;
}

void outputList(list l) {
    int i = 0;
    item val;

    while (!emptyList(l)) {
        val = getFirst(l);
        printf("Elemento di posizione %d:", i);
        output_item(val);
        printf("\n");
        l = tailList(l);
        i++;
    }
}

list inputList(int n) {
    item val;
    list l = newList();
	int i;
    for (i = 0; i < n; i++) {
        printf("Elemento di posizione % d: ", i); input_item(&val);
        l = consList(val, l);
    }

// alla fine del ciclo l contiene gli elementi della lista al contrario

    return reverseList(l);
}
