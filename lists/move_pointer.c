#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

list* move_next(list* a)
{
    a = a  -> next;
    if(!a -> flag)
    {
        a = a -> next;
    }
    return a;
}

list* move_prev(list* a)
{
    a = a -> prev;
    if(!a -> flag)
    {
        a = a -> prev;
    }
    return a;
}
