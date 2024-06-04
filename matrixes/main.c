#include "header.h"

int main()
{
    matrix* a;
    matrix* b;
    int n, m, mk, nk, hk, wk, str1, str2;

    printf("Enter the size of matrix a: \n");
    scanf("%d", &n);
    a = matrix_alloc(n, n);
    printf("Enter matrix a:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double x;
            scanf("%lf", &x);
            change_elem(a, i, j, x);
        }
    }

    printf("Matrix exp\n");
    printf("Enter eps:\n");
    double eps;
    scanf("%lf", &eps);
    b = matrix_exp(a, eps);
    printf("Matrix exponent result:\n");
    matrix_print(b);
    matrix_free(b);

    printf("Matrix transposing\n");
    printf("Enter the sizes for matrix a:\n");
    scanf("%d%d", &mk, &n);
    matrix_free(a);
    a = matrix_alloc(mk, n);
    printf("Enter matrix for transposing:\n");
    for (int i = 0; i < mk; i++) {
        for (int j = 0; j < n; j++) {
            double x;
            scanf("%lf", &x);
            change_elem(a, i, j, x);
        }
    }
    a = self_transpose(a);
    printf("Transposed matrix:\n");
    matrix_print(a);
    matrix_free(a);

    printf("Swap two strings in matrix a:\n");
    printf("Enter the sizes for matrix a:\n");
    scanf("%d%d", &n, &m);
    a = matrix_alloc(m, n);
    printf("Enter matrix a:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; ++j) {
            double x;
            scanf("%lf", &x);
            change_elem(a, i, j, x);
        }
    }
    printf("matrix a:\n");
    matrix_print(a);
    printf("Enter number of strings:\n");
    scanf("%d%d", &str1, &str2);
    swap_strings(a, str1, str2);
    printf("Matrix after swapping strings:\n");
    matrix_print(a);
    matrix_free(a);


    printf("Gauss method:\n");
    printf("Enter the sizes for matrix a:\n");
    scanf("%d%d", &n, &m);
    a = matrix_alloc(n, m + 1);
    matrix* A = matrix_alloc(n, m);
    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            double x;
            scanf("%lf", &x);
            change_elem(a, i, j, x);
            if (j < m)
            {
                change_elem(A, i, j, x);
            }
        }
    }

    b = gauss(a);
    printf("Solution:\n");
    if (isnan(in_index(b, 0, 0)))
    {
        printf("No solutions or infinite number of solutions\n");
    }
    else
    {
        matrix_print(b);
    }

    printf("Multiplying matrix and vector:\n");
    matrix* c=matrix_alloc(n, 1);
    c = matrix_multipl(A, b, c);
    printf("Result of multiplying A and b:\n");
    matrix_print(c);

    printf("Adding matrices:\n");
    printf("Enter the sizes for matrix a:\n");
    scanf("%d%d", &mk, &nk);
    matrix_free(a);
    a = matrix_alloc(mk, nk);
    printf("Enter matrix a:\n");
    for (int i = 0; i < mk; i++) {
        for (int j = 0; j < nk; j++) {
            double x;
            scanf("%lf", &x);
            change_elem(a, i, j, x);
        }
    }

    printf("Enter the sizes for matrix b:\n");
    scanf("%d%d", &hk, &wk);
    matrix_free(b);
    b = matrix_alloc(hk, wk);
    printf("Enter matrix b:\n");
    for (int i = 0; i < hk; i++) {
        for (int j = 0; j < wk; j++) {
            double x;
            scanf("%lf", &x);
            change_elem(b, i, j, x);
        }
    }

    matrix* d = adding(a, b);
    printf("Result of adding a and b:\n");
    matrix_print(d);

    matrix_free(A);
    matrix_free(a);
    matrix_free(c);
    matrix_free(b);
    matrix_free(d);

    getch();
    return 0;
}
