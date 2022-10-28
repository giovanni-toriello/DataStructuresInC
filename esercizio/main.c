#include <stdio.h>
#include "item.h"
#include "BTree.h"
#include "esame.h"

int main() {
    FILE *fp, *fp1;
    fp = fopen("albero.txt", "r");
    Btree b = finputBtree(fp);
    stampa(b);
    printf("\n\n%d", fogliaVicina(b));
}
