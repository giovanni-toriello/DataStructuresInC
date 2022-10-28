typedef struct node *BST;

// prototipi
BST newBST(void);

int emptyBST(BST T);

BST figlioSX(BST T);

BST figlioDX(BST T);

BST insert(BST T, item elem);

int contains(BST T, item elem);

BST deleteNode(BST T, item elem);

void stampa(BST t);

BST creaBilanciatoBst(int a[], int n);

int isBst(BST b);

void stampaIntervallo(BST t, int a, int b);

