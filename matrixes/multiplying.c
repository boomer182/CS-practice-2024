#include "header.h"

matrix* matrix_multipl(matrix* a, matrix* b, matrix* c)
{

    if(size_n(a)!=size_m(b))
    {
        return NULL;
    }

    if(!c)
    {
        c = matrix_alloc(size_m(a), size_n(b));
        if(!c)
        {
            return NULL;
        }

    }

    else
    {

        c = matrix_resize(c, size_m(a), size_n(b));
        if(!c)
        {
            return NULL;
        }
    }


    for (size_t i = 0; i < size_m(a); i++) {
        for (size_t j = 0; j < size_n(b); j++) {
            element_t sum = 0;
            for (size_t k = 0; k < size_n(a); k++) {
                sum += in_index(a, i, k) * in_index(b, k, j);
            }
            change_elem(c, i, j, sum);
        }
    }
    return c;
}

matrix* number_multipl(matrix* a, element_t b)
{
    if(!a)
    {
        return NULL;
    }

    size_t m = size_m(a);
    size_t n = size_n(a);

    for(size_t i=0; i<m; i++)
    {
        for(size_t j=0; j<n; j++)
        {
            change_elem(a, i, j, in_index(a, i, j) * b);
        }
    }
    return a;
}
