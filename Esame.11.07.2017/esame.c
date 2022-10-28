//
// Created by nucle on 24/10/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "queue.h"
#include "esame.h"

queue estraiMaxN(queue q, int n) {
    if (q == NULL) {
        return NULL;
    }
    item *elementi;
    int size = 20;
    elementi = malloc(sizeof(item) * size);
    int numElementi = 0;
    while (!emptyQueue(q)) {
        if (numElementi == size) {
            size += 10;
            elementi = realloc(elementi, sizeof(item) * size);
        }
        elementi[numElementi] = dequeue(q);
        numElementi++;
    }
    if (n > numElementi) {
        return NULL;
    }
    int i = 0;
    item max = newItem(0);
    while (i < n) {
        if (getValue(elementi[i]) > getValue(max)) {
            max = elementi[i];
            i = 0;
        }
        i++;
    }
    for (i = 0; i < numElementi; ++i) {
        if (!eq(max, elementi[i])) {
            enqueue(elementi[i], q);
        }
    }
    free(elementi);
    free(max);
    return q;
}

queue insertMinN(queue q, item el, int n) {
    if (q == NULL) {
        return NULL;
    }
    if (el == NULL) {
        return NULL;
    }
    item *elementi;
    int size = 20;
    elementi = malloc(sizeof(item) * size);
    int numElementi = 0;
    while (!emptyQueue(q)) {
        if (numElementi == size) {
            size += 10;
            elementi = realloc(elementi, sizeof(item) * size);
        }
        elementi[numElementi] = dequeue(q);
        numElementi++;
    }
    if (n > numElementi) {
        return NULL;
    }
    int i = 0;
    item min = elementi[n];
    while (i < n) {
        if (getValue(elementi[i]) < getValue(min)) {
            min = elementi[i];
        }
        i++;
    }
    for (i = 0; i < numElementi; i++) {
        item corr = elementi[i];
        if (eq(corr, min)) {
            enqueue(el, q);
        }
        enqueue(corr, q);
    }
    return q;
}