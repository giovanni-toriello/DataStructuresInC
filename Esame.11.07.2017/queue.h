// file queue.h

typedef struct c_queue *queue;

// prototipi

queue newQueue(void);

int emptyQueue(queue q);

item dequeue(queue q);

int enqueue(item val, queue q);
