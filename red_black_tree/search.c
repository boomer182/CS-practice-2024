#include "header.h"

rb_node* rb_search (rb_tree *t, key_t key)
{
    rb_node *x = t->root;

    while (x)
    {
        if      (key < x->key) x = x->left;
        else if (key > x->key) x = x->right;
        else return x;
    }

    return NULL;
}

rb_node* minim (rb_tree *t)
{
    rb_node *x = t->root;
    if (!x) return NULL;
    while (x->left) x = x->left;
    return x;
}

rb_node* maxim (rb_tree *t)
{
    rb_node *x = t->root;
    if (!x) return NULL;
    while (x->right) x = x->right;
    return x;
}
