#include <stdio.h>
#include "item.h"
#include "queue.h"
#include "esame.h"

int main() {
    queue q = newQueue();
    enqueue(newItem(200), q);
    enqueue(newItem(500), q);
    enqueue(newItem(27), q);
    enqueue(newItem(789), q);
    enqueue(newItem(123), q);
    enqueue(newItem(556), q);
    enqueue(newItem(12354), q);
    enqueue(newItem(89), q);
    enqueue(newItem(123), q);
    enqueue(newItem(4), q);
    q = estraiMaxN(q, 5);
    q = insertMinN(q, newItem(3030), 9);
    while (!emptyQueue(q)) {
        output_item(dequeue(q));
        printf("\n");
    }
}
