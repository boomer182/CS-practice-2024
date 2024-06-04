#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "structures.h"
#include "stack.h"

double pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("Error. Stack is empty\n");
        return NULL;
    }
    node *temp = s->top;
    double data = temp->data;
    s->top = temp->next;
    free(temp);
    return data;
}
