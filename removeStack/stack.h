
typedef struct c_stack *stack;

stack newStack(void);

int emptyStack(stack s);

int pop(stack s);

int push(item val, stack s);

item top(stack s);

stack input_stack();

stack inversione(stack s);

void append(stack s1, stack s2);

void remove_item(stack temp, int n);