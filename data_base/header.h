#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stddef.h>

struct student;

struct group;

struct group* new_group();

int st_add (struct group *g, int a, double b, char* s);

int st_del(struct group *g, size_t k);

void say(struct group *g);

void fsay(struct group *g, char *s);

typedef int (*cmp) (struct student, struct student);

int pointu(struct student a, struct student b);

int apointu(struct student a, struct student b);

int podoblu(struct student a, struct student b);

int apodoblu(struct student a, struct student b);

int postringu(struct student a, struct student b);

int apostringu(struct student a, struct student b);

void start_heap_sort(struct group *g, cmp c);

int add_from_file(struct group *g, char* s);

void destroy(struct group* g);

int bar_data(struct group* g, int x);

int circle_data(struct group* g, int x);

#endif // HEADER_H_INCLUDED
