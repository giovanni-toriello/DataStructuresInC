//
// Created by nucle on 24/10/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "BTree.h"
#include "PQueue.h"
#include "esame.h"

int Fogliek(Btree T, int k) {
    int countFoglie = 0;
    if (T == NULL) {
        return 0;
    }
    if (k == 1) {
        if (figlioSX(T) == NULL && figlioDX(T) == NULL) {
            return 1;
        } else {
            return 0;
        }
    }
    countFoglie += Fogliek(figlioSX(T), k - 1);
    countFoglie += Fogliek(figlioDX(T), k - 1);

    return countFoglie;
}

void PriorityQueueIncrease(PQueue q) {
    int *elementi;
    int size = 10;
    elementi = malloc(sizeof(int) * size);
    int numElementi = 0;
    while (!emptyPQ(q)) {
        if (numElementi == size) {
            size += 10;
            elementi = realloc(elementi, sizeof(int) * size);
        }
        elementi[numElementi] = getMax(q);
        deleteMax(q);
        numElementi++;
    }
    int i;
    insert(q, elementi[0]);
    for (i = 1; i < numElementi; i++) {
        insert(q, elementi[i] + 1);
    }
    free(elementi);
}

int strutturalmenteSimili(Btree t1, Btree t2) {
    int okSx = 0;
    int okDx = 0;
    if (t1 == NULL && t2 != NULL) {
        return 0;
    }
    if (t1 != NULL && t2 == NULL) {
        return 0;
    }
    if (t1 == NULL && t2 == NULL) {
        return 1;
    }
    if (figlioSX(t1) == NULL && figlioSX(t2) == NULL) {
        okSx = 1;
    }
    if (figlioDX(t1) == NULL && figlioDX(t2) == NULL) {
        okDx = 1;
    }
    if (figlioSX(t1) != NULL && figlioSX(t2) != NULL) {
        okSx = strutturalmenteSimili(figlioSX(t1), figlioSX(t2));
    }
    if (figlioDX(t1) != NULL && figlioDX(t2) != NULL) {
        okDx = strutturalmenteSimili(figlioDX(t1), figlioDX(t2));
    }
    if (okSx == okDx) {
        return 1;
    }
    return 0;
}