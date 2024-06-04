#include "header.h"

rb_tree *rb_alloc()
{
    rb_tree *r = malloc (sizeof(rb_tree));
    if (!r) return NULL;

    r->root = NULL;
    return r;
}

void rb_node_clear (rb_node *n)
{
    if (!n) return;
    rb_node_clear (n->left);
    rb_node_clear (n->right);
    free(n);
}

void rb_free(rb_tree *t)
{
    rb_node_clear (t->root);
    free(t);
}
