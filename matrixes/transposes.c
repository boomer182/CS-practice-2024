#include "header.h"

void element_swap(element_t* a, element_t* b)
{
    element_t c=*a;
    *a=*b;
    *b=c;
}

matrix* transpose(matrix* a, matrix* b)
{
    size_t m_a = size_m(a);
    size_t n_a = size_n(a);

    if(!b)
    {
        b = matrix_alloc(n_a, m_a);
        if (!b)
        {
            return NULL;
        }

    }
    else
    {
        if (b->m != n_a || b->n != m_a)
        {
            b = matrix_resize(b, n_a, m_a);
            if (!b)
            {
                return NULL;
            }
        }
    }

    for(size_t i = 0; i < m_a; i++)
    {
        for(size_t j = 0; j < n_a; j++)
        {
            element_t val = in_index(a, i, j);
            change_elem(b, j, i, val);
        }
    }
    return b;
}

matrix* self_transpose(matrix* a)
{
    if(!a)
    {
        return NULL;
    }

    size_t m = size_m(a);
    size_t n = size_n(a);

    matrix *b = null_alloc(n, m);
    b = transpose(a, b);

    if(!b)
    {
        return NULL;
    }

    matrix* c = a;
    a = b;
    matrix_free(c);
    return a;
}
