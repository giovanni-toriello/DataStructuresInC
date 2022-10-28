#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node {
    item value;
    struct node *next;
};

struct c_stack {
    struct node *top;
    int numel;
};

stack newStack(void) {
    stack s;
    s = malloc(sizeof(struct c_stack));
    if (s == NULL)
        return NULL;
    s->numel = 0;
    s->top = NULL;
    return s;
}

int emptyStack(stack s) {
    return s->numel == 0;
}

int push(item val, stack s) {
    struct node *nuovo;
    nuovo = malloc(sizeof(struct node));

    if (nuovo == NULL)
        return 0;

    nuovo->value = val;
    nuovo->next = s->top;
    s->top = nuovo;
    (s->numel)++;

    return 1;
}

int pop(stack s) {
    if (s->numel == 0)
        return 0;

    struct node *temp;
    temp = s->top;
    s->top = s->top->next;
    free(temp);
    (s->numel)--;

    return 1;
}

item top(stack s) {
    item e;

    if (s->numel > 0)
        e = s->top->value;
    else
        e = NULL;

    return e;
}

stack input_stack() {
    int i = 0;
    stack s = newStack();
    int inserisco = 0;
    while (1) {
        printf("Elemento n.%d:", i++);
        scanf("%d", &inserisco);
        if (inserisco == -1) {
            break;
        }
        push(newItem(inserisco), s);
    }
    return s;
}

stack inversione(stack s) {
    stack s2 = newStack();
    while (!emptyStack(s)) {
        push(top(s), s2);
        pop(s);
    }
    return s2;
}

void append(stack s1, stack s2) {
    stack s3 = newStack();
    struct node *temp;
    int i = 0;
    int j = s2->numel;
    temp = s2->top;
    int k = 0;
    while (i < s2->numel) {
        item e = temp->value;
        k++;
        if (k == j) {
            push(e, s3);
            temp = s2->top;
            j--;
            k = 0;
            i++;
        } else {
            temp = temp->next;
        }
    }
    i = 0;
    j = s1->numel;
    temp = s1->top;
    k = 0;
    while (i < s1->numel) {
        item e = temp->value;
        k++;
        if (k == j) {
            push(e, s3);
            temp = s1->top;
            j--;
            k = 0;
            i++;
        } else {
            temp = temp->next;
        }
    }
    while (!emptyStack(s3)) {
        output_item(top(s3));
        pop(s3);
    }
}

void remove_item(stack s1, int n) {
    if (s1->top == NULL) {
        return;
    }
    item canc = newItem(n);
    item curr = s1->top->value;
    if (!eq(curr, canc)) {
        s1->top = s1->top->next;
        push(curr, s1);
        remove_item(s1, n);
    }
    if (eq(curr, canc)) {
        s1->top = s1->top->next;
        remove_item(s1, n);
        pop(s1);
    }
}