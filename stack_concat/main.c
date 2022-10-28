#include <stdio.h>
#include <stdlib.h>
#include "esame.h"

int main(){
    stack s1 = newStack();
    stack s2 = newStack();
    for (int i = 0; i <10 ; ++i) {
        item e = newItem(i);
        push(e,s1);
        push(e,s2);
    }
    inserisci(s1,s2);
    while (!emptyStack(s1)){
        item e = top(s1);
        output_item(e);
        printf("\n");
        pop(s1);
    }
}
