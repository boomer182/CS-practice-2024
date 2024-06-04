#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "structure.h"
#include "stack.h"
#include "calculator.h"

double evaluate(double operand1, double operand2, char op)
{
    switch(op)
    {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0)
            {
                printf("Ошибка: Деление на ноль\n");
                exit(EXIT_FAILURE);
            }
            return operand1 / operand2;
        case '^':
            return pow(operand1, operand2);
        default:
            printf("Ошибка: Неверный оператор\n");
            exit(EXIT_FAILURE);
    }
}
