
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
struct oggetto{
    int intero;
};
int eq(item x, item y) {
    return x->intero == y->intero;
}
item newItem(int i)
{
    struct oggetto* e = malloc(sizeof(struct oggetto));
    if(e != NULL)
    {
        e->intero = i;
    }
    return e;
}
void output_item(item x) {
    printf("%d", x->intero);
}
item input_item() {
    int x = 0;
    scanf("%d", &x);
    item e = newItem(x);
    return e;
}
