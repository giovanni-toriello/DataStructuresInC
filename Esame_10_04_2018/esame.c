#include "esame.h"
#include <stdio.h>
#include <stdlib.h>

int cancDaItem(item e, queue q) {
    if (e == NULL || emptyQueue(q)) {
        return -1;
    }
    queue q2 = newQueue();
    int trovato = 0;
    while (!emptyQueue(q)) {
        item item1 = dequeue(q);
        if (eq(item1, e)) {
            trovato = 1;
        }
        if (trovato) {
            dequeue(q);
        }
        if (!trovato) {
            enqueue(item1, q2);
        }
    }
    while (!emptyQueue(q2)) {
        item item1 = dequeue(q2);
        enqueue(item1, q);
    }
    free(q2);
    return 1;
}

queue fondiQueue(queue q1, queue q2) {
    queue q3 = newQueue();
    item *queue1, *queue2, *queue3;
    queue1 = malloc(sizeof(item) * 20);
    queue2 = malloc(sizeof(item) * 20);

    int countQ1 = 0;
    while (!emptyQueue(q1)) {
        item e = dequeue(q1);
        if (countQ1 == 20) {
            queue1 = realloc(queue1, sizeof(item) * 20);
        }
        queue1[countQ1] = e;
        countQ1++;
    }
    int countQ2 = 0;
    while (!emptyQueue(q2)) {
        item e = dequeue(q2);
        if (countQ2 == 20) {
            queue2 = realloc(queue2, sizeof(item) * countQ2);
        }
        queue2[countQ2] = e;
        countQ2++;
    }
    queue3 = malloc(sizeof(item) * countQ1 + countQ2);
    int countQ3 = 0;
    for (int i = 0; i < countQ1; i++) {
        item e = queue1[i];
        for (int j = 1; j < countQ2; ++j) {
            item b = queue2[j];
            if (eq(e, b)) {
                queue3[countQ3] = e;
                countQ3++;
            }
        }
    }
    for (int i = 0; i < countQ3; ++i) {
        item e = queue3[i];
        for (int j = 1; j < countQ3; ++j) {
            if (eq(e, queue3[j])) {
                item b = newItem(-1);
                queue3[j] = b;
            }
        }
    }
    for (int i = 0; i < countQ3; ++i) {
        item b = newItem(-1);
        if (!eq(queue3[i], b)) {
            enqueue(queue3[i], q3);
        }
    }
    free(q1);
    free(q2);
    free(queue1);
    free(queue2);
    free(queue3);
    return q3;

}//due temp per confrontare