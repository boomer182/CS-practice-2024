#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

int isOperator(char oper);

double evaluate(double operand1, double operand2, char op);

double evaluateRPN(char* expression);

#endif // CALCULATOR_H_INCLUDED
