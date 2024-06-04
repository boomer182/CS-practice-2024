#include "header.h"

void swap_strings(matrix* a, size_t x, size_t y)
{
    size_t current_n = size_n(a);
    element_t* b = malloc(current_n * sizeof(element_t));
    for(size_t j=0; j < current_n; j++)
    {
        b[j] = in_index(a, x, j);
    }
    for(size_t j = 0; j < current_n; j++)
    {
        element_t w = in_index(a, y, j);
        change_elem(a, x, j, w);
    }
    for(size_t j=0; j < current_n; j++)
    {
        change_elem(a, y, j, b[j]);
    }
    free(b);
}

void minus_str(matrix* a, size_t x, size_t y, element_t c)
{
    size_t current_n = size_n(a);
    for(size_t j=0; j < current_n; j++)
    {
        element_t k = in_index(a, x, j);
        element_t l = in_index(a, y, j);
        change_elem(a, x, j, k-c*l);
    }
}

void multipl_str(matrix* a, size_t x, element_t c)
{
    size_t n = size_n(a);
    for(size_t j=0; j < n; j++)
    {
        element_t k=in_index(a, x, j);
        change_elem(a, x, j, k*c);
    }
}

