#include "header.h"

matrix* adding(matrix* a, matrix* b)
{
    if(!a||!b)
    {
        return NULL;
    }

    size_t m = size_m(a);
    size_t n = size_n(a);

    if(m!= size_m(b) || n!= size_n(b))
    {
        return NULL;
    }

    for(size_t i = 0; i < m; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            element_t sum = in_index(a, i, j) + in_index(b, i, j);
            change_elem(a, i, j, sum);
        }
    }
    return a;
}


