#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "structure.h"
#include "stack.h"
#include "calculator.h"

int isOperator(char op)
{
    return op == '+' || op == '-' || op == '*' || op == '/' || op == '^';
}


