#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "structure.h"
typedef struct list list;

list* create();

list* create_copy(list* a);

list* add_after(list* a, int x);

list* add_before(list* a, int x);

list* elem_delete(list* a);

list* move_next(list* a);

list* move_prev(list* a);

int print_elem(list* a);

void print_list(list* a);

void list_free(list* a);

#endif // LIST_H_INCLUDED
