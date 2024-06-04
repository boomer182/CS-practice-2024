#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

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

struct list
{
    list* prev;
    list* next;
    int num;
    int flag;
};

#endif // HEADER_H_INCLUDED
