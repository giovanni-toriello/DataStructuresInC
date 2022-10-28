// file queue.h

typedef struct c_queue *queue;

// prototipi

queue newQueue(void);

int emptyQueue(queue q);

punto dequeue(queue q);

queue create_queue_punti();

int enqueue(punto val, queue q);

queue sottocoda(queue q, int quadrante);

float spezzata(queue q);

queue concatenazione(queue q1, queue q2);
