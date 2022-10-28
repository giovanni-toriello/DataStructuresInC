#include <stdio.h>
#include "PQueue.h"

int main() {
    PQueue p = newPQ();
    insert(p, 11);
    insert(p, 131);
    insert(p, 114);
    insert(p, 171);
    insert(p, 111);
    insert(p, 117);
    insert(p, 112);
    insert(p, 41);
    insert(p, 1);
    insert(p, 20);
    PQueue p2 = newPQ();
    insert(p2, 43);
    insert(p2, 87);
    insert(p2, 12);
    insert(p2, 30);
    insert(p2, 55);
    insert(p2, 78);
    insert(p2, 21);
    insert(p2, 34);
    insert(p2, 66);
    insert(p2, 17777);
    PQueue q3 = merge(p,p2);
}