#include "header.h"

int black_height(rb_tree *t)
{
    if (t == NULL || t->root == NULL)
    {
        return 0;
    }

    rb_node *current = t->root;
    int black_height = 0;

    while (current)
    {
        if (current->color == black)
        {
            black_height++;
        }
        current = current->left;
    }

    return black_height;
}

int red_height(rb_node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    if (node->color == red)
    {
        return 1 + fmax(red_height(node->left), red_height(node->right));
    }

    return fmax(red_height(node->left), red_height(node->right));
}

int max_red_height(rb_tree *tree)
{
    if (tree == NULL || tree->root == NULL)
    {
        return 0;
    }

    return red_height(tree->root);
}


int tree_height(rb_node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        int left_height = tree_height(node->left);
        int right_height = tree_height(node->right);

        return (left_height > right_height) ? (left_height + 1) : (right_height + 1);
    }
}



