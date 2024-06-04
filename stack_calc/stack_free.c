#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "structures.h"
#include "stack.h"

void stack_free(stack *s)
{
    while (!isEmpty(s))
    {
        pop(s);
    }
    free(s);
}
