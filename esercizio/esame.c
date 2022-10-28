#include "item.h"
#include <stdio.h>
#include "BTree.h"
#include "esame.h"

int countFogliaVicina(Btree t, int n);

int fogliaVicina(Btree t) {
    return countFogliaVicina(t, 0);
}

int countFogliaVicina(Btree t, int n) {
    if (t == NULL) {
        return n;
    }
    int countSX, countDX;
    if (figlioSX(t) == NULL && figlioDX(t) == NULL) {
        return n;
    }
    countSX = countFogliaVicina(figlioSX(t), n + 1);
    countDX = countFogliaVicina(figlioDX(t), n + 1);
    if (countSX < countDX) {
        return countSX;
    } else {
        return countDX;
    }
}