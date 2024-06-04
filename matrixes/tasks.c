#include "header.h"

matrix* gauss(matrix* a)
{
    size_t n = size_m(a);
    size_t m = size_n(a);
    matrix* x = matrix_alloc(n, 1);

    for (size_t i = 0; i < n; i++)
    {
        double max_elem = fabs(in_index(a, i, i));
        size_t max_row = i;
        for (size_t k = i + 1; k < n; k++)
        {
            if (fabs(in_index(a, k, i)) > max_elem)
            {
                max_elem = fabs(in_index(a, k, i));
                max_row = k;
            }
        }

        if (i != max_row)
        {
            swap_strings(a, i, max_row);
        }

        for (size_t k = i + 1; k < n; k++)
        {
            double c = -in_index(a, k, i) / in_index(a, i, i);
            for (size_t j = i; j < m; j++)
            {
                if (i == j)
                {
                    change_elem(a, k, j, 0);
                }
                else
                {
                    change_elem(a, k, j, in_index(a, k, j) + c * in_index(a, i, j));
                }
            }
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        double x_i = in_index(a, i, m - 1) / in_index(a, i, i);
        change_elem(x, i, 0, x_i);

        for (int k = i - 1; k >= 0; k--)
        {
            double c = -in_index(a, k, i) * x_i;
            change_elem(a, k, m - 1, in_index(a, k, m - 1) + c);
        }
    }

    return x;
}

matrix* matrix_exp(matrix* a, element_t eps)
{
    if(eps!=eps)
    {
        return NULL;
    }
    size_t ma = size_m(a);
    size_t na = size_n(a);
    if(ma!= na)
    {
        return NULL;
    }
    element_t A=1.0/0.0;
    if(A == eps)
    {
        return NULL;
    }
    matrix* deg = e_alloc(ma, na);
    matrix* cur = null_alloc(ma, na);
    double N=1;
    while(matrix_norm(deg)>= eps)
    {
        matrix* x = null_alloc(ma, na);
        cur = adding(cur, deg);
        x=matrix_multipl(deg, a, x);
        x=number_multipl(x, 1/N);
        N++;
        matrix* y=deg;
        deg=x;
        matrix_free(y);
    }
    cur=adding(cur, deg);
    matrix_free(deg);
    return cur;
}

element_t matrix_norm(matrix* a)
{
    size_t current_m = size_m(a);
    size_t current_n = size_n(a);
    element_t norm = 0;

    for(size_t i=0; i < current_n; i++)
    {
        element_t cur_norm = 0;

        for(size_t j = 0; j < current_m; j++)
        {
            cur_norm+=fabs(in_index(a, j, i));
        }
        norm = fmax(norm, cur_norm);
    }
    return norm;
}
