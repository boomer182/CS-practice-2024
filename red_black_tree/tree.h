#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include "tree_actions.h"

typedef enum {red, black} rb_color;

typedef int key_t;

typedef struct rb_node
{
    key_t key;
    rb_color color;
    struct rb_node *left, *right, *parent;
} rb_node;

typedef struct rb_tree
{
    rb_node *root;
} rb_tree;

rb_tree *rb_alloc();

void rb_node_clear(rb_node *n);

void rb_free(rb_tree *t);

void print(const rb_node *t);

rb_node *rb_search(rb_tree *t, key_t key);

rb_node *minim(rb_tree *t);

rb_node *maxim(rb_tree *t);

void left_rotate(rb_tree *t, rb_node *x);

void right_rotate(rb_tree *t, rb_node *x);


#endif // TREE_H_INCLUDED
