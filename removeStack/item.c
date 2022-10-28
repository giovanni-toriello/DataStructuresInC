
#include <stdio.h>
#include <stdlib.h>
#include "item.h"



int eq(item x, item y) {
    return x == y;
}

void output_item(item x) {
    printf("%d", x);
}

item input_item() {
    int x = 0;
    scanf("%d", &x);
    return x;
}

int minore(item x, item y) {
    return x < y;
}