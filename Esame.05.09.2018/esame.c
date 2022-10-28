//
// Created by nucle on 24/10/2022.
//
#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "PQueue.h"
#include "esame.h"

list listKeys(PQueue q) {
    return createList(q);
}

PQueue remGreatestKeys(PQueue q, int k) {
    int size = 10;
    int *array = malloc(sizeof(int) * size);
    int i = 0;
    int n = 0;
    while (!emptyPQ(q)) {
        if (n == size) {
            size += 10;
            array = realloc(array, sizeof(int) * size);
        }
        if (getMax(q) >= k) {
            array[n] = getMax(q);
            n++;
        }
        deleteMax(q);
        i++;
    }
    for (int j = 0; j <n ; ++j) {
        insert(q,array[j]);
    }
    return q;
}