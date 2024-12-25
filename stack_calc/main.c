#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "structure.h"
#include "stack.h"
#include "calculator.h"
#include <locale.h>

int main() {
    setlocale(LC_CTYPE, "Russian");

    char expression[100];
    printf("Введите выражение в обратной польской записи: ");
    fgets(expression, 100, stdin);

    double result = evaluateRPN(expression);
    printf("Результат: %.2f\n", result);

    return 0;
}
