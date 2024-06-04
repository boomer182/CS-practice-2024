#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "structure.h"
#include "stack.h"
#include "calculator.h"

double evaluateRPN(char* expression)
{
    stack *s = stack_init();
    char* token = strtok(expression, " ");

    while (token != NULL)
        {
        if (isdigit(*token) || (strlen(token) > 1 && *token == '-' && isdigit(token[1])))
        {
            push(s, atof(token)); // Преобразование строки в double и добавление числа в стек
        } else if (isOperator(*token))
        {
            if (isEmpty(s) || s->top->next == NULL)
            {
                printf("Ошибка: Недостаточно операндов для выполнения операции\n");
                exit(EXIT_FAILURE);
            }
            double operand2 = pop(s);
            double operand1 = pop(s);
            double result = evaluate(operand1, operand2, *token);
            push(s, result); // Добавление результата операции в стек
        } else if (strcmp(token, "pi") == 0)
        {
            push(s, M_PI); // Добавление значения pi в стек
        } else if (strcmp(token, "e") == 0)
        {
            push(s, M_E); // Добавление значения e в стек
        } else
        {
            printf("Ошибка: Неверный формат оператора или операнда\n");
            exit(EXIT_FAILURE);
        }
        token = strtok(NULL, " ");
    }

    if (isEmpty(s) || s->top->next != NULL)
    {
        printf("Ошибка: Недостаточно операций или лишние операнды\n");
        exit(EXIT_FAILURE);
    }

    double result = pop(s); // Получение результата из стека
    stack_free(s);
    return result;
}
