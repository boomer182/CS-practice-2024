#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "structures.h"
#include "stack.h"


void push(stack *s, double data)
{
    node *new_node = malloc(sizeof(node));
    if (!new_node)
    {
        printf("Error\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}
