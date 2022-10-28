#include <stdio.h>
#include <stdlib.h>
#include "PQueue.h"

#define MAXPQ 50

struct c_PQ {
    int vet[MAXPQ];
    int numel;
};

static void scendi(PQueue q);

static void sali(PQueue q);

PQueue newPQ(void) {
    PQueue q;
    q = malloc(sizeof(struct c_PQ));
    if (q == NULL) return NULL;
    q->numel = 0;
    return q;
}

int emptyPQ(PQueue q) {
    if (!q) return 1;
    return q->numel == 0;
}


int getMax(PQueue q) {
    return q->vet[1];
    // NON VERIFICA LA
    // PRECONDIZIONE
    // LA CODA NON PUO’
    // ESSERE VUOTA
}

int deleteMax(PQueue q) {
    if (!q || q->numel == 0) return 0;   // CODA VUOTA

    q->vet[1] = q->vet[q->numel];  //SPOSTO L’ULTIMO ELEMENTO
    q->numel--;                               // IN POSIZIONE 1

    scendi(q);      // RIAGGIUSTO LO HEAP SCENDENDO

    return 1;
}

static void scendi(PQueue q) {
    int temp, n = q->numel, i = 1, pos;

    while (1) {
        if (2 * i + 1 <= n)               // IL NODO CORRENTE HA 2 FIGLI
            pos = (q->vet[i * 2] > q->vet[i * 2 + 1]) ? i * 2 : i * 2 + 1;

        else if (2 * i <= n)          // IL NODO CORRENTE HA 1 FIGLIO
            pos = 2 * i;
        else break;                  // IL NODO CORRENTE NON HA FIGLI

        if (q->vet[pos] > q->vet[i])     // SCAMBIO LE CHIAVI E PROSEGUO
        {
            temp = q->vet[i];
            q->vet[i] = q->vet[pos];
            q->vet[pos] = temp;
            i = pos;
        } else
            break;   // NON CI SONO PIU’ SCAMBI DA FARE, MI FERMO
    }
}

static void sali(PQueue q) {
    int temp, pos = q->numel, i = pos / 2;

    while (pos > 1) {

        if (q->vet[pos] > q->vet[i]) {
            temp = q->vet[i];
            q->vet[i] = q->vet[pos];
            q->vet[pos] = temp;
            pos = i;
            i = pos / 2;
        } else
            break;
    }
}

int dammiMassimo(PQueue q) {
    int max = 0;
    while (!emptyPQ(q)) {
        int val = getMax(q);
        if (max < val) {
            max = val;
        }
        deleteMax(q);
    }
    return max;
}

int dammiMinimo(PQueue q) {
    if (emptyPQ(q)) {
        return -1;
    }
    int min = getMax(q);
    while (!emptyPQ(q)) {
        int val = getMax(q);
        if (min > val) {
            min = val;
        }
        deleteMax(q);
    }
    return min;
}

int insert(PQueue q, int key) {
    if (!q || q->numel == MAXPQ) return 0; // CODA PIENA
    q->numel++;
    q->vet[q->numel] = key; // INSERISCI IN ULTIMA POSIZIONE
    sali(q); // AGGIUSTA LO HEAP RISALENDO
    return 1;
}

PQueue incrementaValore(PQueue q, int key, int newK) {
    PQueue q1 = newPQ();
    while (!emptyPQ(q)) {
        int val = getMax(q);
        if (val == key) {
            val = newK;
        }
        deleteMax(q);
        insert(q1, val);
    }
    return q1;
}

int *heapify(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; ++j) {
            int x = a[i];
            int y = a[j];
            if (x < y) {
                int temp = a[i];
                a[i] = y;
                a[j] = temp;
            }
        }
    }
    return a;
}

PQueue merge(PQueue q1, PQueue q2) {
    int array[MAXPQ];
    int n = 0;
    PQueue q3 = newPQ();
    while (!emptyPQ(q1) && n < MAXPQ) {
        array[n] = getMax(q1);
        deleteMax(q1);
        n++;
    }
    for (int i = 0; i < n; i++) {
        insert(q3, array[i]);
        insert(q1, array[i]);
    }
    n = 0;
    while (!emptyPQ(q2) && n < MAXPQ) {
        array[n] = getMax(q2);
        deleteMax(q2);
        n++;
    }
    for (int i = 0; i < n; i++) {
        insert(q3, array[i]);
        insert(q2, array[i]);
    }
    return q3;

}