typedef struct node *list;

list newList(void);

int emptyList(list l);

list tailList(list l);

list consList(punto val, list l);

punto getFirst(list l);

int sizeList(list l);

int countMinori(list l, float d);

int posItem(list l, punto val);

punto getItem(list l, int pos);

list reverseList(list l);

void outputList(list l);

list inputList(int n);

list distanzaMassima(list l);

list insertList(list l, int pos, punto val);

void riordina(list l, char coordinata[], char criterio[]);

list removeList(list l, int pos);