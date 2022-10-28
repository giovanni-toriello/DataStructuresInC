#include <stdio.h>
#include "esame.h"

int main() {
    lista l1 = newList();
    lista l2 = newList();
    int i;
    for (i = 0; i < 10; i++) {
        printf("Lista 1: elemento %d\n", i);
        item uno = input_item();
        printf("Lista 2: elemento %d\n", i);
        item due = input_item();
        l1 = consList(uno, l1);
        l2 = consList(due, l2);
    }
    item elemento = newItem(5);
    lista l3 = fondiDaItem(l1, l2, elemento);
    while (!emptyList(l3)) {
        item e = getFirst(l3);
        output_item(e);
        l3 = tailList(l3);
    }
}
