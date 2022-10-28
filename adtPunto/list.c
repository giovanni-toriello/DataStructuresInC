#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "punto.h"
#include "list.h"

struct node {
    punto value;
    struct node *next;
};


list newList(void) {
    return NULL;
}

int emptyList(list l) {
    return l == NULL;
}


list consList(punto val, list l) {
    struct node *nuovo;
    nuovo = malloc(sizeof(struct node));
    if (nuovo != NULL) {
        nuovo->value = val;
        nuovo->next = l;
        l = nuovo;
    }
    return l;
}

list tailList(list l) {
    list temp;
    if (l != NULL)
        temp = l->next;
    else
        temp = NULL;
    return temp;
}

// uso tipico dell’operatore:
//   L = tailList(L);
punto getFirst(list l) {
    punto e;
    if (l != NULL)
        e = l->value;
    else
        e = NULL;
    return e;
}

int sizeList(list l) {
    int n = 0;
    while (!emptyList(l)) // finché non raggiungiamo la fine della lista
    {
        n++;            // il primo elemento contribuisce al conteggio
        l = tailList(l);    // continuiamo la visita degli elementi successivi
    }
    return n;
}

int posItem(list l, punto val) {
    int pos = 0; // contatore di posizione
    int found = 0;

    while (!emptyList(l) && !found) {
        if (eq(getFirst(l), val))
            found = 1;
        else {
            pos++; // incrementa il contatore di posizione
            l = tailList(l);  // continuiamo la visita degli elementi della lista
        }
    }

    if (!found)
        pos = -1;  // se non trovato restituiamo come posizione -1

    return pos;
}

punto getItem(list l, int pos) {
    punto e;
    int i = 0;
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

list reverseList(list l) {
    list rev;
    punto val;

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
    punto val;

    while (!emptyList(l)) {
        val = getFirst(l);
        printf("Elemento di posizione %d:", i);
        stampa(val);
        printf("\n");
        l = tailList(l);
        i++;
    }
}

list removeList(list l, int pos) {
    list l1, prec; // puntatore al nodo da eliminare
    int i;
    if (pos == 0 && l != NULL) { // eliminazione in posizione 0
        l1 = l;
        l = tailList(l);
        free(l1);
    } else { // se non dobbiamo cancellare in posizione 0, scorriamo
// la lista fino alla posizione precedente a quella del
// nodo da eliminare
        i = 0;
        prec = l;
        while (i < pos - 1 && prec != NULL) {
            prec = prec->next;
            i++;
        }
        if (prec != NULL && prec->next != NULL) { // short-circuit evaluation
            l1 = prec->next;
            prec->next = l1->next;
            free(l1);
        }
    }
    return l;
}

list inputList(int n) {
    punto val;
    list l = newList();

    for (int i = 0; i < n; i++) {
        printf("Elemento di posizione % d: \n", i);
        val = input_punto();
        l = consList(val, l);
    }


    return reverseList(l);
}

list insertList(list l, int pos, punto val) {
    punto x;
    int i = 0;
    list ltmp = newList();
    list lo = newList();

    while (i < pos && !emptyList(l)) {
        x = getFirst(l);
        ltmp = consList(x, ltmp);
        l = tailList(l);
        i++;
    }

    if (i == pos) {
        lo = consList(val, l);
        while (!emptyList(ltmp)) {
            x = getFirst(ltmp);
            lo = consList(x, lo);
            ltmp = tailList(ltmp);
        }
    }
    return (lo);
}


int countMinori(list l, float d) {
    int count = 0;
    for (int i = 0; i < sizeList(l) - 1; i++) {
        printf("\nPrendo punto %d: ", i);
        for (int j = i + 1; j < sizeList(l); ++j) {
            printf("\nConfronto con %d: ", j);
            if (distanza(getItem(l, i), getItem(l, j)) < d) {
                printf("\tMaggiore %f", distanza(getItem(l, i), getItem(l, j)));
                count++;
            } else {
                printf("\tMinore %f", distanza(getItem(l, i), getItem(l, j)));
            }
        }
    }
    return count;
}

list distanzaMassima(list l) {
    list distanzaMassima = newList();
    float max = 0;
    punto a = NULL;
    punto b = NULL;
    for (int i = 0; i < sizeList(l) - 1; i++) {
        printf("\nPrendo punto %d: ", i);
        for (int j = i + 1; j < sizeList(l); ++j) {
            printf("\nConfronto con %d: ", j);
            float dist = distanza(getItem(l, i), getItem(l, j));
            if (dist > max) {
                max = dist;
                a = creaPunto(ascissa(getItem(l, i)), ordinata(getItem(l, i)));
                b = creaPunto(ascissa(getItem(l, j)), ordinata(getItem(l, j)));
                printf("\tDistanza Massima %f", dist);
            }
        }
    }
    distanzaMassima = consList(a, distanzaMassima);
    distanzaMassima = consList(b, distanzaMassima);
    return distanzaMassima;
}

void riordina(list l, char coordinata[], char criterio[]) {
    list l1 = l;
    int swapped;
    while (l1->next != NULL) {
        swapped = 0;
        punto p1 = l1->value;
        punto p2 = l1->next->value;
        if (!strcmp(coordinata, "ascissa")) {
            if (!strcmp(criterio, "decrescente")) {
                if (ascissa(p1) < ascissa(p2)) {
                    l1->value = p2;
                    l1->next->value = p1;
                    swapped = 1;
                }
                if (swapped != 1) {
                    l1 = l1->next;
                }
                if (swapped == 1) {
                    l1 = l;
                }
            }
            if (!strcmp(criterio, "crescente")) {
                if (ascissa(p1) > ascissa(p2)) {
                    l1->value = p2;
                    l1->next->value = p1;
                    swapped = 1;
                }
                if (swapped != 1) {
                    l1 = l1->next;
                }
                if (swapped == 1) {
                    l1 = l;
                }
            }
        }
        if (!strcmp(coordinata, "ordinata")) {
            if (!strcmp(criterio, "decrescente")) {
                if (ordinata(p1) < ordinata(p2)) {
                    l1->value = p2;
                    l1->next->value = p1;
                    swapped = 1;
                    l1 = l;
                }
                if (swapped != 1) {
                    l1 = l1->next;
                }
            }
            if (!strcmp(criterio, "crescente")) {
                if (ordinata(p1) > ordinata(p2)) {
                    l1->value = p2;
                    l1->next->value = p1;
                    swapped = 1;
                }
                if (swapped != 1) {
                    l1 = l1->next;
                }
                if (swapped == 1) {
                    l1 = l;
                }
            }
        }
    }
}