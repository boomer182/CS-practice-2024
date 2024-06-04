#include "header.h"

void left_rotate(rb_tree *t, rb_node *x)
{
    rb_node *y = x->right;
    assert (y);


    x->right = y->left;
    if (y->left)
        y->left->parent = x;
    if (!x->parent)
        t->root = y;
    else
    {
        if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

    }
    y->parent = x->parent;

    y->left = x;
    x->parent = y;
}

void right_rotate(rb_tree *t, rb_node *x)
{
    rb_node *y = x->left;
    assert (y);

    x->left = y->right;
    if (y->right)
        y->right->parent = x;

    if (!x->parent)
        t->root = y;
    else
        if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

    y->parent = x->parent;

    y->right = x;
    x->parent = y;
}
