#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"
#include "esame.h"

void rimuoviDuplicati(stack s) {
    item *elementi;
    int size = 10;
    elementi = malloc(sizeof(item) * size);
    int numEl = 0;
    int j = 0;
    while (!emptyStack(s)) {
        int duplicato = 0;
        if (numEl == size) {
            size += 10;
            elementi = realloc(elementi, sizeof(item) * size);
        }
        item curr = top(s);
        for (j = 0; j < numEl; j++) {
            if (eq(elementi[j], curr)) {
                duplicato = 1;
            }
        }
        if (!duplicato) {
            elementi[numEl] = curr;
            numEl++;
        }
        pop(s);
    }
    int i;
    for (i = numEl; i >= 0; i--) {
        push(elementi[i], s);
    }
    free(elementi);
}