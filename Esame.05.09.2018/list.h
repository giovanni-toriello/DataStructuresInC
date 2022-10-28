// file list.h


typedef struct node *list;

// prototipi

list newList(void);

int emptyList(list l);

list tailList(list l);

list consList(int val, list l);

int getFirst(list l);

int sizeList(list l);

int posItem(list l, int val);

int getItem(list l, int pos);

list reverseList (list l);

void outputList (list l);

list inputList (int n);
