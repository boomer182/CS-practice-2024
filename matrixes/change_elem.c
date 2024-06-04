#include "header.h"

void change_elem(matrix* a, size_t i, size_t j, element_t x)
{
    size_t N=a->n;
    a->mat[i*N+j]=x;          //elem index = i*N+j
}

element_t in_index(matrix* matr, size_t i, size_t j)
{
    size_t N=matr->n;
    return matr->mat[i*N+j];
}

