#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int print_elem(list* a)
{
    return a->num;
}

void print_list(list* a)
{
    list* b=a;
    list* c=b;
    if(b->flag)
    {
        printf("%d ", b->num);
    }
    b=b->next;
    while(b!=c)
    {
        if(b->flag)
        {
            printf("%d ", b->num);
        }
        b=b->next;
    }
    printf("\n");
}
