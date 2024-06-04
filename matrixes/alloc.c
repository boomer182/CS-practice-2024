#include "header.h"

matrix* matrix_alloc(size_t given_m, size_t given_n)
{
    matrix* a= malloc(sizeof(matrix));
    size_t x = given_m * given_n;
    if(x<10)
    {
        x=10;
    }
    a -> MAX = x;
    a -> mat = malloc(x*sizeof(element_t));
    a -> m = given_m;
    a -> n = given_n;
    return a;
}

matrix* null_alloc(size_t given_m, size_t given_n)
{
    matrix* a= matrix_alloc(given_m, given_n);
    for(size_t i=0; i<given_m*given_n; i++)
    {
        a->mat[i]=0;
    }
    return a;
}

matrix* e_alloc(size_t given_m, size_t given_n)
{
    matrix* matr = matrix_alloc(given_m, given_m);
    for(size_t i=0; i<given_m * given_n; i++)
    {
        size_t y=i-(i/given_m)*given_n;
        if((i/given_m)!=y)
        {
            matr->mat[i]=0;
        }
        else
        {
            matr->mat[i]=1;
        }
    }
    return matr;
}

matrix* matrix_copy(matrix* a, matrix* b)
{
    if(!a)
    {
        return NULL;
    }
    size_t ma = size_m(a);
    size_t na = size_n(a);
    if(!b)
    {
        b = matrix_alloc(ma, na);

    }
    else
    {
        b = matrix_resize(b, ma, na);
    }
    if(!b)
    {
        return NULL;
    }
    for(size_t i = 0; i < ma; i++)
    {
        for(size_t j = 0; j  <na; j++)
        {
            change_elem(b, i, j, in_index(a, i, j));
        }
    }
    return b;
}


void matrix_free(matrix* matr)
{
    if(matr != NULL)
    {
        free(matr->mat);
        free(matr);
        matr = NULL;
    }
}

