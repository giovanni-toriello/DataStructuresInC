#include <stdio.h>
#include "item.h"
#include "list.h"
#include "esame.h"

list scambiaUltimo(list l, item first,int n) {
    if (emptyList(l)) {
        return NULL;
    }
    item e = getFirst(l);
    l = scambiaUltimo(tailList(l), first,n+1);
    if (l == NULL) {
        l = consList(first, l);
        output_item(e);
        l = consList(e, l);
        return l;
    }
    item last = getFirst(l);
    if (n!=0) {
        l = tailList(l);
        l = consList(e, l);
        l = consList(last, l);
    }
    return l;
}