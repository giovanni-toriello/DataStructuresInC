#include <stdio.h>
#include "item.h"
#include "stack.h"
#include "BTree.h"
#include "esame.h"

int main() {
    stack stack1 = newStack();
    stack stack2 = newStack();
    for (int i = 50; i < 100; ++i) {
        push(newItem(i), stack2);
    }
    stack_inserisci(newStack(), stack2);
    while (!emptyStack(stack1)) {
        output_item(top(stack1));
        pop(stack1);
        printf("\n");
    }
}
