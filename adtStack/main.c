#include <stdio.h>
#include "stack.h"

int main() {
    stack s1 = input_stack();
    remove_item(s1,1);
    while (!emptyStack(s1)){
        printf("\nMain:");
        output_item(top(s1));
        pop(s1);
        printf("\n");
    }
}
