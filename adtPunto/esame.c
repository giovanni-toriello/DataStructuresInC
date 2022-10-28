#include <stdio.h>
#include <malloc.h>
#include "punto.h"
#include "list.h"
#include "esame.h"

list sottolista(int m, int n, list l) {
    int i = 0;
    list l2 = newList();
    list result = newList();
    while (!emptyList(l)) {
        if (i < m || i > n) {
            l2 = consList(getFirst(l), l2);

        } else if (i >= m && i <= n) {
            result = consList(getFirst(l), result);
        }
        l = tailList(l);
        i++;
    }
    l = reverseList(l2);
    free(l2);
    return reverseList(result);
}

list inserisci_lista(list l, list k, int m) {
    int i;
    list temp = newList();
    for (i = 0; i < m; ++i) {
        temp = consList(getFirst(l), temp);
        l = tailList(l);
    }
    while (!emptyList(k)) {
        temp = consList(getFirst(k), temp);
        k = tailList(k);
    }
    while (!emptyList(l)) {
        temp = consList(getFirst(l), temp);
        l = tailList(l);
    }
    l = reverseList(temp);
    free(temp);
    return l;
}
