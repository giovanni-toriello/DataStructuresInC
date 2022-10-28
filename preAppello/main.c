#include <stdio.h>
#include "item.h"
#include "BTree.h"
#include "PQueue.h"
#include "esame.h"

int main() {
    FILE *fp, *fp1;
    fp = fopen("albero.txt", "r");
    fp1 = fopen("albero1.txt", "r");
    Btree b = finputBtree(fp);
    Btree c = finputBtree(fp1);
    printf("%d\n\n", Fogliek(b, 3));
    PQueue q = newPQ();
    for (int i = 0; i < 20; ++i) {
        insert(q, i);
    }
    PriorityQueueIncrease(q);
    while (!emptyPQ(q)) {
        printf("\n%d", getMax(q));
        deleteMax(q);
    }

    printf("\n\nUguali:%d", strutturalmenteSimili(NULL, c));
}
