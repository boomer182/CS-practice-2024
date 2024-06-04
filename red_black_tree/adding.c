#include "header.h"

rb_node *bst_insert (rb_tree *t, key_t key)
{
    rb_node *y = NULL, *x = t->root;
    rb_node *z = malloc(sizeof(rb_node));
    if (!z) return NULL;

    z->key   = key;
    z->color = red;
    z->left  = z->right   = NULL;

    while (x)
    {
        y = x;
        if (z->key == x->key)
        {
            free(z);
            return NULL;
        }
        x = z->key < x->key ? x->left
                            : x->right;
    }

    z->parent = y;
    if (!y)
        t->root = z;
    else
    {
        if (z->key < y->key)
            y->left = z;
        else
            y->right = z;
    }

    return z;
}


int rb_insert (rb_tree *t, key_t key)
{
    rb_node *x = bst_insert(t, key);
    if (!x) return 1;

    while (x != t->root && x->parent->color == red)
    {
        rb_node *y = x->parent == x->parent->parent->left ? x->parent->parent->right : x->parent->parent->left;

        if (y && y->color == red)
        {
            x->parent->color = black;
            y->color = black;
            x->parent->parent->color = red;
            x = x->parent->parent;

        }
        else
        {
            if (x->parent == x->parent->parent->left && x == x->parent->right)
            {
                x = x->parent;
                left_rotate(t, x);
            }
            else if (x->parent == x->parent->parent->right && x == x->parent->left)
            {
                x = x->parent;
                right_rotate(t, x);
            }

            x->parent->color  = black;
            x->parent->parent->color = red;

            x == x->parent->left ? right_rotate(t, x->parent->parent) : left_rotate (t, x->parent->parent);
        }
    }

    t->root->color = black;
    return 0;
}

void rb_delete_fix(rb_tree *t, rb_node *x)
{
    while (x != t->root && x->color == black)
    {
        if (x == x->parent->left)
        {
            rb_node *w = x->parent->right;
            if (w->color == red)
            {
                w->color = black;
                x->parent->color = red;
                left_rotate(t, x->parent);
                w = x->parent->right;
            }
            if (w->left->color == black && w->right->color == black)
            {
                w->color = red;
                x = x->parent;
            }
            else
            {
                if (w->right->color == black)
                {
                    w->left->color = black;
                    w->color = red;
                    right_rotate(t, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = black;
                w->right->color = black;
                left_rotate(t, x->parent);
                x = t->root;
            }
        }
        else
        {
            rb_node *w = x->parent->left;
            if (w->color == red)
            {
                w->color = black;
                x->parent->color = red;
                right_rotate(t, x->parent);
                w = x->parent->left;
            }
            if (w->right->color == black && w->left->color == black)
            {
                w->color = red;
                x = x->parent;
            }
            else
            {
                if (w->left->color == black)
                {
                    w->right->color = black;
                    w->color = red;
                    left_rotate(t, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = black;
                w->left->color = black;
                right_rotate(t, x->parent);
                x = t->root;
            }
        }
    }
    x->color = black;
}


int rb_delete(rb_tree *t, key_t key)
{
    rb_node *z = t->root;

    while (z && z->key != key)
    {
        z = key < z->key ? z->left : z->right;
    }

    if (!z)
    {
        return -1;
    }

    rb_node *y = z;
    rb_node *x = y->right ? y->right : y->left;

    if (!z->left || !z->right)
    {
        y = z;
    }

    else
    {
        rb_tree r;
        r.root = z->right;
        y = minim(&r);
        z->key = y->key;
        x = y->right;
    }

    if (!x)
    {
        x = malloc(sizeof(rb_node));
        x->color = black;
        x->parent = y->parent;
        if (!y->parent)
            t->root = x;
        else if (y == y->parent->left)
        {
            y->parent->left = x;
        }
        else
        {
            y->parent->right = x;
        }
    }

    if (y->color == black)
    {
        rb_delete_fix(t, x);
    }

    free(y);

    return 0;
}
