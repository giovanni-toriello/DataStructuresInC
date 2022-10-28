#include <stdio.h>
#include "list.h"
#include "PQueue.h"
#include "esame.h"

int main() {
    PQueue q = newPQ();
    insert(q, 1);
    insert(q, 2);
    insert(q, 3);
    insert(q, 4);
    insert(q, 5);
    insert(q, 6);
    insert(q, 7);
    insert(q, 8);
    insert(q, 9);
    insert(q, 10);
    q = remGreatestKeys(q,5);
    while (!emptyPQ(q)){
        printf("\n%d", getMax(q));
        deleteMax(q);
    }
}
