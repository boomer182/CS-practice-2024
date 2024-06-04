#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

stack *stack_init();

int isEmpty(stack *s);

void push(stack *s, double data);

double pop(stack *s);

void stack_free(stack *s);


#endif // STACK_H_INCLUDED
