#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED
#include "list.h"
struct list
{
    list* prev;
    list* next;
    int num;
    int flag;
};

#endif // STRUCTURE_H_INCLUDED
