#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "structures.h"
#include "stack.h"

stack *stack_init() {
    stack *s = malloc(sizeof(*s));
    if (!s) {
        return NULL;
    }
    s->top = NULL;
    return s;
}
