#include <stdlib.h>
#include <stdio.h>
#include "esame.h"

int main() {
    queue q1 = newQueue();
    queue q2 = newQueue();
    for (int i = 0; i < 10; ++i) {
        item e = newItem(i);
        enqueue(e, q1);
    }
    for (int i = 5; i < 20; ++i) {
        item e = newItem(i);
        enqueue(e, q2);
    }
    queue q3;
    q3 = fondiQueue(q1, q2);
    while (!emptyQueue(q3)){
        item e = dequeue(q3);
    }
}