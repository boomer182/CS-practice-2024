#ifndef TREE_ACTIONS_H_INCLUDED
#define TREE_ACTIONS_H_INCLUDED
#include "tree.h"

typedef int key_t;

typedef struct rb_node rb_node;

typedef struct rb_tree rb_tree;

int rb_insert (rb_tree *t, key_t key);

rb_node *bst_insert (rb_tree *t, key_t key);

int rb_delete(rb_tree *t, key_t key);

void rb_delete_fix(rb_tree *t, rb_node *x);

int rb_rcount(rb_node *node);

int rb_count(rb_tree *t);

int rb_rleaves(rb_node *node);

int rb_leaves(rb_tree *t);

int black_height(rb_tree *t);

int red_height(rb_node *node);

int max_red_height(rb_tree *tree);

#endif // TREE_ACTIONS_H_INCLUDED
