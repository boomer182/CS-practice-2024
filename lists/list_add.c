#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

list* add_before(list* a, int x)
{
    list* b=malloc(sizeof(list));
    b->num=x;
    b->flag=1;
    b->next=a;
    b->prev=a->prev;
    a->prev->next=b;
    a->prev=b;
    if(!a->flag)
    {
        a=a->prev;
    }
    return a;
}

list* add_after(list* a, int x)
{
    list* b=malloc(sizeof(list));
    b->num=x;
    b->flag=1;
    b->prev=a;
    b->next=a->next;
    a->next->prev=b;
    a->next=b;
    if(!a->flag)
    {
        a=a->next;

    }
    return a;
}
