#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

list* elem_delete(list* a)
{
    if(a->flag==0)
    {
        return a;
    }
    a->prev->next=a->next;
    a->next->prev=a->prev;
    list* b=a;
    a=a->next;
    free(b);
    if(!a->flag)
    {
        a=a->next;
    }
    return a;
}
