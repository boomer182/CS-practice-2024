#include "header.h"

void print(const rb_node *t)
{
    if (t)
    {
        print(t->left);

        printf ("%i (%s, ", t->key, t->color == red ? "red" : "black");
        if (t->parent) printf("parent = %i) ", t->parent->key); else printf("root) ");

        print(t->right);
    }
}
