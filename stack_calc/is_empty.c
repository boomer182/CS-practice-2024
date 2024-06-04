#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "structures.h"
#include "stack.h"

int is_empty(stack *s)
{
    return s->top == NULL;
}
