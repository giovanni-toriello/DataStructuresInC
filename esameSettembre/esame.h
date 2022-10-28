/**
 * conta_figliUnici: conta i figli unici di un btree,
 *  Specifica Semantica:
 *          conta_figliUnici(btree)->int
 *  Specifica Sintattica:
 *          pre: btree>0
 *          post: se l'albero è vuoto int=0, se l'albero ha dei nodi che hanno un solo figlio somma al totale+1;
 */
int conta_figliUnici(Btree b);
/**
 * stack_inserisci: inserisci gli elementi di s2(stack in input) a metà s1,
 *  Specifica Semantica:
 *          stack_inserisci(stack,stack)->void
 *  Specifica Sintattica:
 *          pre: s1>0, s1 non nullo AND s2 non nullo.
 *          post: s1 = <(s1,1),(s1,2),(s2,1)(s2,2),(s2,3),(s1,3),(s1,4)>.
 */
void stack_inserisci(stack s1,stack s2);