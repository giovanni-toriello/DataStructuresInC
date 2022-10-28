#include <stdio.h>
#include <stdlib.h>
#include "punto.h"
#include "queue.h"

struct node {
    punto value;
    struct node *next;
};

struct c_queue {
    struct node *head, *tail;
    int numel;
};

queue newQueue(void) {
    struct c_queue *q;
    q = malloc(sizeof(struct c_queue));
    if (q == NULL)
        return NULL;

    q->numel = 0;
    q->head = NULL;
    q->tail = NULL;
    return q;
}

int emptyQueue(queue q) {
    if (q == NULL)
        return -1;
    return q->numel == 0;
}

int enqueue(punto val, queue q) {
    if (q == NULL)
        return -1;

    struct node *nuovo;
    nuovo = malloc(sizeof(struct node));
    if (nuovo == NULL) return 0;

    nuovo->value = val;
    nuovo->next = NULL;

    if (q->head == NULL)
        q->head = nuovo;         //  caso coda vuota
    else
        q->tail->next = nuovo;  //  caso coda non vuota

    q->tail = nuovo;                // tail punta al nuovo nodo
    (q->numel)++;                   // incrementare il numero di elementi
    return 1;
}

punto dequeue(queue q) {
    if (q == NULL) return NULL;

    if (q->numel == 0) return NULL;    //  coda vuota

    punto result = q->head->value;   //  item da restituire

    struct node *temp = q->head;   //  nodo da rimuovere

    q->head = q->head->next;        // q->head avanza
    free(temp);                 // liberiamo memoria nodo da rimuovere

    if (q->head == NULL)   // se la coda conteneva un solo elemento
        q->tail = NULL;

    (q->numel)--;

    return result;
}

queue create_queue_punti() {
    queue q = newQueue();
    int inserisco = 0;
    int i = 0;
    while (inserisco != -1) {
        printf("Elemento n.%d\n", i++);
        punto p = input_punto();
        enqueue(p, q);
        printf("Per uscire inserire -1 o qualsiasi numero per continuare...\n");
        scanf("%d", &inserisco);
    }
    return q;
}

queue sottocoda(queue q, int quadrante) {
    queue temp = q;
    queue primoQ = newQueue();
    queue secondoQ = newQueue();
    queue terzoQ = newQueue();
    queue quattroQ = newQueue();
    while (!emptyQueue(temp)) {
        punto e = dequeue(temp);
        if (ascissa(e) >= 0) {
            if (ordinata(e) >= 0) {
                enqueue(e, primoQ);
            } else {
                enqueue(e, quattroQ);
            }
        }
        if (ascissa(e) < 0) {
            if (ordinata(e) < 0) {
                enqueue(e, terzoQ);
            } else {
                enqueue(e, secondoQ);
            }
        }
    }
    if (quadrante == 1) {
        return primoQ;
    }
    if (quadrante == 2) {
        return secondoQ;
    }
    if (quadrante == 3) {
        return terzoQ;
    }
    if (quadrante == 4) {
        return quattroQ;
    }
    return NULL;
}

float spezzata(queue q) {
    float spezzata = 0;
    punto temp = dequeue(q);
    while (!emptyQueue(q)) {
        punto a = dequeue(q);
        spezzata += distanza(a, temp);
        temp = a;
    }
    return spezzata;
}

queue concatenazione(queue q1, queue q2) {
    queue q3 = newQueue();
    while (!emptyQueue(q2)) {
        enqueue(dequeue(q2), q3);
    }
    while (!emptyQueue(q1)) {
        enqueue(dequeue(q1), q3);
    }
    return q3;
}
