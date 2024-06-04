#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

typedef struct node
{
    double data;
    struct node *next;
} node;

typedef struct stack
{
    node *top;
} stack;

#endif // STRUCTURE_H_INCLUDED
