#include <stdio.h>
#include "item.h"
#include "list.h"
#include "esame.h"

int main(int argc, char **argv) {
    int i;
    list l = newList();
    for (int j = 0; j < 11; ++j) {
        l = consList(newItem(j),l);
    }
    for (int j = 11; j >1; --j) {
        l = consList(newItem(j), l);
    }
    printf("Non modificata:\n");
    outputList(l);
    printf("\nModificata\n");
    l = scambiaUltimo(l, getFirst(l), 0);
    outputList(l);
}
