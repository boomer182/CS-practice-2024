#include "header.h"

size_t size_m(matrix* matrix)
{
    return matrix->m;
}

size_t size_n(matrix* matrix)
{
    return matrix->n;
}

matrix* matrix_resize(matrix* matr, size_t given_m, size_t given_n)
{
    if (matr == NULL || matr->mat == NULL)
    {
        return NULL;
    }

    size_t new_size = given_m * given_n;
    if (new_size > matr->MAX)
    {
        size_t new_max;
        if (new_size < 2 * matr->MAX)
        {
            new_max = 2 * matr->MAX;
        }
        else
        {
            new_max = new_size;
        }

        element_t* new_mat = realloc(matr->mat, new_max * sizeof(element_t));
        if (new_mat == NULL)
        {
            return NULL;
        }

        matr->mat = new_mat;
        matr->MAX = new_max;
    }

    matr->m = given_m;
    matr->n = given_n;
    return matr;
}
