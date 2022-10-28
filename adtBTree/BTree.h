typedef struct node *Btree;

// prototipi

Btree newBtree(void);

int emptyBtree(Btree T);

Btree figlioSX(Btree T);

Btree figlioDX(Btree T);

Btree consBtree(item val, Btree sx, Btree dx);

struct node *getRoot(Btree T);

Btree inputBtree(void);

void inorder(Btree T);

Btree finputBtree(FILE *finput);

void stampa(Btree a);

void printBtree(Btree albero, int lv);

int countLeaf(Btree b);

char uguali(Btree b1, Btree b2);

int min(Btree b);

Btree specchiata(Btree b);

Btree aggiungiNodo(Btree b, item nodo);

int max(Btree b);

int isBst(Btree t);