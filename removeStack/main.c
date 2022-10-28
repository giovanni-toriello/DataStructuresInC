#include <stdio.h>
#include "item.h"
#include "stack.h"
#include "esame.h"

int main() {
    stack s = newStack();
    for (int i = 0; i < 10; ++i) {
        push(i, s);
    }
    push(8, s);
    push(7, s);
    push(10, s);
    push(4, s);
    rimuoviDuplicati(s);
    while (!emptyStack(s)){
        printf("\n");
        output_item(top(s));
        pop(s);
    }
}
