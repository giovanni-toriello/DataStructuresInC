#include <stdio.h>
#include <malloc.h>
#include "stack.h"
#include "BTree.h"

int conta_figliUnici(Btree b) {
    if (b == NULL) {
        return 0;
    }
    int countFigli = 0;
    if (figlioSX(b) == NULL && figlioDX(b) != NULL || figlioSX(b) != NULL && figlioDX(b) == NULL) {
        countFigli += 1;
    }
    countFigli += conta_figliUnici(figlioSX(b));
    countFigli += conta_figliUnici(figlioDX(b));
    return countFigli;
}

void stack_inserisci(stack s1, stack s2) {
    item *array1;
    item *array2;
    int size = 20;
    array1 = malloc(sizeof(item) * size);
    int n = 0;
    while (!emptyStack(s1)) {
        if (n == size) {
            size += 20;
            array1 = realloc(array1, sizeof(item) * size);
        }
        array1[n] = top(s1);
        pop(s1);
        n++;
    }
    size = 0;
    int j = 0;
    array2 = malloc(sizeof(item) * size);
    while (!emptyStack(s2)) {
        if (j == size) {
            size += 20;
            array2 = realloc(array2, sizeof(item) * size);
        }
        array2[j] = top(s2);
        pop(s2);
        j++;
    }
    for (int i = n-1; i >= 0; --i) {
        push(array1[i], s1);
        if (i == (int) n / 2) {
            for (int k = j-1; k >= 0; --k) {
                push(array2[k], s1);
            }
        }
    }
    free(array1);
    free(array2);
}