#include <stdio.h>
#include "item.h"
#include "queue.h"
#include "esame.h"


int main() {
    queue q1 = newQueue();
    queue q2 = NULL;
    for (int i = 1; i <= 40; ++i) {
        enqueue(newItem(i), q1);
    }
    printf("Found: %d\n", presenteQ(q1, newItem(27)));
    queue q3 = xorQ(q1, q2);
    printf("XOR di q1,q2: ");
    while (!emptyQueue(q3)) {
        output_item(dequeue(q3));
        printf("-");
    }
}
