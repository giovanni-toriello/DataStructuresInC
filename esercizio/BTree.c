#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "BTree.h"

struct node {
    item value;
    struct node *left;
    struct node *right;
};

item getItem(struct node *N);

void setItem(struct node *N, item el);

item getItem(struct node *N) {
    if (N == NULL) return NULL;
    return N->value;
}

void setItem(struct node *N, item el) {
    if (N == NULL) return;
    N->value = el;  // correttezza di =
}                             // dipende dal tipo item
Btree newBtree(void) {
    return NULL;
}

int emptyBtree(Btree T) {
    return T == NULL;
}

struct node *getRoot(Btree T) {
    return T;
}

Btree consBtree(item val, Btree sx, Btree dx) {
    struct node *nuovo;
    nuovo = malloc(sizeof(struct node));
    if (nuovo != NULL) {
        setItem(nuovo, val);
        nuovo->left = sx;
        nuovo->right = dx;
    }
    return nuovo;
}

Btree figlioSX(Btree T) {
    if (T != NULL)
        return T->left;
    else
        return NULL;
}

Btree figlioDX(Btree T) {
    if (T != NULL)
        return T->right;
    else
        return NULL;
}

Btree inputBtree(void) {
    Btree T1, T2;
    int ris;
    item el;
    printf("\nL'albero è vuoto? (1/0): ");
    scanf("%d", &ris);
    if (ris) return newBtree();
    printf("\nInserisci la radice: ");
    input_item(&el);
    printf("costruisco il sottoalbero SX\n");
    T1 = inputBtree();
    printf("costruisco il sottoalbero DX\n");
    T2 = inputBtree();
    return consBtree(el, T1, T2);
}

void inorder(Btree T) {
    if (emptyBtree(T)) return;
    inorder(figlioSX(T));
    output_item(getItem(getRoot(T)));
    inorder(figlioDX(T));
}

Btree finputBtree(FILE *finput) {
    Btree new, sx, dx;
    char stop[20];
    item el;

    if (feof(finput)) {
        return newBtree();
    }
    fscanf(finput, "%s", stop);
    if (!strcmp(stop, "stop")) {
        return newBtree();
    }
    el = newItem(atoi(stop));
    new = newBtree();
    sx = finputBtree(finput);
    dx = finputBtree(finput);
    new = consBtree(el, sx, dx);
    return new;
}

void printBtree(Btree albero, int lv) {
    item val;
    if (emptyBtree(albero)) {
        return;
    }
    int i;
    for (i=0; i < lv - 1; ++i) {
        printf("|  ");
    }
    if (lv > 0) {
        printf("|--");
    }
    val = getItem(getRoot(albero));
    output_item(val);
    printf("\n");
    printBtree(figlioSX(albero), lv + 1);
    printBtree(figlioDX(albero), lv + 1);
}

void stampa(Btree albero) {
    printBtree(albero, 0);
}

int countLeaf(Btree b) {
    int sx = 0, dx = 0;
    if (b == NULL) {
        return 0;
    }
    if (figlioSX(b) == NULL && figlioDX(b) == NULL) {
        return 1;
    } else {
        sx = countLeaf(figlioSX(b));
        dx = countLeaf(figlioDX(b));
    }
    return sx + dx;
}

Btree specchiata(Btree b) {
    Btree sx, dx;
    if (b == NULL) {
        return NULL;
    }
    sx = specchiata(figlioSX(b));
    dx = specchiata(figlioDX(b));
    b = consBtree(getItem(b), dx, sx);
    return b;
}

int max(Btree b) {
    if (b == NULL) {
        return 0;
    }
    int massimo = 0;
    int value = getValue(getItem(b));
    int sx = 0, dx = 0;
    sx = max(figlioSX(b));
    dx = max(figlioDX(b));
    if (sx > dx) {
        massimo = sx;
    } else {
        massimo = dx;
    }
    if (massimo < value) {
        massimo = value;
    }
    return massimo;
}

int min(Btree b) {
    if (b == NULL) {
        return 0;
    }
    int minimo = 0;
    int value = getValue(getItem(b));
    int sx = 0, dx = 0;
    sx = min(figlioSX(b));
    dx = min(figlioDX(b));
    if (sx > dx) {
        minimo = dx;
    } else {
        minimo = sx;
    }
    if (value < minimo) {
        minimo = value;
    }
    return minimo;
}

char uguali(Btree b1, Btree b2) {
    char sx = 'd', dx = 'd';
    if (b1 == NULL) {
        if (b2 == NULL) {
            return 'u';
        }
        return 'd';
    }
    if (eq(getItem(b1), getItem(b2))) {
        sx = uguali(figlioSX(b1), figlioSX(b2));
        dx = uguali(figlioDX(b1), figlioDX(b2));
        if (dx == 'u' && sx == 'u') {
            return 'u';
        }
    }
    return 'd';
}

Btree aggiungiNodo(Btree b, item nodo) {
    Btree new = NULL;
    if (b == NULL) {
        return consBtree(nodo, newBtree(), newBtree());
    }
    if (figlioSX(b) == NULL) {
        new = aggiungiNodo(figlioSX(b), nodo);
    } else if (figlioDX(b) == NULL) {
        new = aggiungiNodo(figlioDX(b), nodo);
    }
    new = aggiungiNodo(b, nodo);
    return b;
}

int isBst(Btree t) {
    int isBstSX = 0;
    int isBstDX = 0;
    item father = getItem(t);
    if (figlioSX(t) != NULL && figlioDX(t) != NULL) {
        item itemSX = getItem(figlioSX(t));
        item itemDX = getItem(figlioDX(t));
        if (getValue(father) > getValue(itemSX)) {
            isBstSX = 1;
        }
        if (getValue(father) < getValue(itemDX)) {
            isBstDX = 1;
        }
        if (isBstDX && isBstSX) {
            isBstSX = isBst(figlioSX(t));
            isBstDX = isBst(figlioDX(t));
            if (isBstSX && isBstDX) {
                return 1;
            }
        }
        return 0;
    } else {
        return 1;
    }
    return 0;
}
