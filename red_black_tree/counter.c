#include "header.h"

int rb_rcount(rb_node *node)
{
    if (!node)
        return 0;

    return 1 + rb_rcount(node->left) + rb_rcount(node->right);
}

int rb_count(rb_tree *t)
{
    if (!t->root)
        return 0;

    return rb_rcount(t->root);
}

int rb_rleaves(rb_node *node)
{
    if (!node)
        return 0;

    if (!node->left && !node->right)
        return 1;

    return rb_rleaves(node->left) + rb_rleaves(node->right);
}


int rb_leaves(rb_tree *t)
{
    if (!t->root)
        return 0;

    return rb_rleaves(t->root);
}
