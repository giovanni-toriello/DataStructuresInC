// file PQueue.h


typedef struct c_PQ *PQueue;

// prototipi

PQueue newPQ(void);

int emptyPQ(PQueue q);

int getMax(PQueue q);

int deleteMax(PQueue q);

int insert(PQueue q, int key);

int dammiMassimo(PQueue q);

int dammiMinimo(PQueue q);

int *heapify(int a[], int n);

PQueue incrementaValore(PQueue q, int key, int newK);

PQueue merge(PQueue q1, PQueue q2);

list createList(PQueue q);