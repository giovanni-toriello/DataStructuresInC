/**
 * presenteQ: controlla se un elemento è presente nella coda.
 * Specifica sintattica:
 *      presenteQ(queue,item)->boolean
 * Specifica semantica:
 *      presenteQ(queue,item)->b
 *       pre: item non nullo.
 *       post: b = true se l'elemento è presente nella coda, b = false se non è presente.
 */
int presenteQ(queue q, item el);

/**
 * xorQ: unione disgiunta degli elementi di due code.
 *  Specifica sintattica:
 *       xor(queue,queue)->queue
 *       post: q'<e1,e2,e3....en> con en che appartiene a q1 o q2 ma non in entrambe.
 *       se q1=0 and q2=0 allora q'= nil,se q1=0 and q2>0 allora q'=q2, se q1>0 and q2=0 allora q'=q1,
 *       se q1==q2 allora q'= 0.
 *  */
queue xorQ(queue q1, queue q2);