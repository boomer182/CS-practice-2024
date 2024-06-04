#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "structure.h"
#include "stack.h"

stack *stack_init()
{
    stack *s = malloc(sizeof(*s));
    if (!s)
    {
        return NULL;
    }
    s->top = NULL;
    return s;
}


int isEmpty(stack *s)
{
    return s->top == NULL;
}

void push(stack *s, double data)
{
    node *newNode = malloc(sizeof(node));
    if (!newNode)
    {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}


double pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("Error: stack is empty\n");
        exit(EXIT_FAILURE);
    }
    node *temp = s->top;
    double data = temp->data;
    s->top = temp->next;
    free(temp);
    return data;
}


void stack_free(stack *s)
{
    while (!isEmpty(s))
    {
        pop(s);
    }
    free(s);
}





