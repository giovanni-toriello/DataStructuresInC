
#include "item.h"
#include "queue.h"
#include "esame.h"
#include <stdio.h>
#include <stdlib.h>

int presenteQ(queue q, item el) {
    item *array;
    int size = 20;
    int found = 0;
    array = malloc(sizeof(item) * size);
    int n = 0;
    while (!emptyQueue(q)) {
        if (n == size) {
            size += 20;
            array = realloc(array, sizeof(item) * size);
        }
        array[n] = dequeue(q);
        if (eq(array[n], el)) {
            found = 1;
        }
        n++;
    }
    for (int i = 0; i < n; ++i) {
        enqueue(array[i], q);
    }
    free(array);
    return found;
}

queue xorQ(queue q1, queue q2) {
    item *queue1;
    int size = 20;
    queue q3 = newQueue();
    queue1 = malloc(sizeof(item) * size);
    int n = 0;
    while (!emptyQueue(q1)) {
        if (n == size) {
            size += 20;
            queue1 = realloc(queue1, sizeof(item) * size);
        }
        queue1[n] = dequeue(q1);
        n++;
    }
    int i;
    for (i = 0; i < n; i++) {
        int trovato = presenteQ(q2, queue1[i]);
        if (!trovato) {
            enqueue(queue1[i], q3);
        }
        enqueue(queue1[i], q1);
    }
    item *queue2;
    size = 0;
    queue2 = malloc(sizeof(item) * size);
    n = 0;
    while (!emptyQueue(q2)) {
        if (n == size) {
            size += 20;
            queue2 = realloc(queue2, sizeof(item) * size);
        }
        queue2[n] = dequeue(q2);
        n++;
    }
    for (i = 0; i < n; i++) {
        int trovato = presenteQ(q1, queue2[i]);
        if (!trovato) {
            enqueue(queue2[i], q3);
        }
        enqueue(queue2[i], q1);
    }
    free(queue1);
    free(queue2);
    return q3;
}