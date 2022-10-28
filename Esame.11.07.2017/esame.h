/**
 * estraiMaxN: estrae dalla coda l'item più grande tra i primi n (parametro input) elementi.
 *   Specifica Semantica:
 *      estraiMaxN(queue,int)->q'
 *   Specifica Sintattica:
 *      pre: n minore del numero di elementi di queue AND queue non nullo.
 *      post: q<e,e1,e2,e3,e4,e5...en> se e è il più grande dei primi n (parametro input) elementi allora q'<e1,e2,e3,e4,e5...en>
 */
queue estraiMaxN(queue q, int n);
/**
 * insertMinN: inserisce l'item el (parametro input) prima del item più piccolo tra i primi n (parametro input) elementi della coda.
 *  Specifica semantica:
 *      insertMinN(queue,item,int)->q'
 *  Specifica Sintattica:
 *      pre: queue non nullo AND item non nullo AND n minore degli elementi di queue.
 *      post: q<e,e1,e2,e3,e4,e5...en> se e è il più piccolo dei primi n (parametro input) elementi allora q'<el,e,e1,e2,e3,e4,e5...en>
 */
queue insertMinN(queue q, item el, int n);