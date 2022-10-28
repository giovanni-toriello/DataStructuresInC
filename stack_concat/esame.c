#include <stdio.h>
#include <stdlib.h>
#include "esame.h"

void inserisci(stack uno,stack due){
    stack tre = newStack();
    int count = 0;
    while (!emptyStack(uno)){
        item e = top(uno);
        push(e,tre);
        pop(uno);
        count++;
    }
    int count2 = 0;
    while (!emptyStack(tre)) {
        item e = top(tre);
        push(e, uno);
        if(count2==count/2){
            while (!emptyStack(due)) {
                push(top(due),uno);
                pop(due);
            }
        }
        pop(tre);
        count2++;
    }
}