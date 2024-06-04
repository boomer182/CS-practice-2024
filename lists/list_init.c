#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

list* create()
{
    list* a = malloc(sizeof(list));
    if(!a)
    {
        return NULL;
    }
    a -> next=a;
    a -> prev=a;
    a -> flag=0;
    return a;
}


list* create_copy(list* a)
{
    list* b=malloc(sizeof(list));
    list* st=b;
    b->num=a->num;
    b->flag=a->flag;
    list* d=a;
    d=a->next;
    while(d!=a)
    {
        list* e=malloc(sizeof(list));
        e->num=d->num;
        e->flag=d->flag;
        b->next=e;
        e->prev=b;
        b=e;
        d=d->next;
    }
    b->next=st;
    st->prev=b;
    return st;
}

void list_free(list* a)
{
    while(a->next!=a)
    {
        a=elem_delete(a);
    }
    free(a);
}

