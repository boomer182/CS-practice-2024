#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

typedef struct matrix matrix;
typedef double element_t;
struct matrix;

///number of rows in the matrix
size_t size_m(matrix* a);

///number of columns in the matrix
size_t size_n(matrix* a);

///resize the matrix by m rows, n columns
matrix* matrix_resize(matrix* a, size_t m, size_t n);

///new matrix with m rows and n columns
matrix* matrix_alloc(size_t given_m, size_t given_n);

///zero matrix with m rows and n columns
matrix* null_alloc(size_t given_m, size_t given_n);

///identity matrix with m rows and n columns
matrix* e_alloc(size_t given_m, size_t given_n);

///copying a matrix
matrix* matrix_copy(matrix* a, matrix* b);

///frees memory allocated for the matrix
void matrix_free(matrix* a);

///change the element with index (i,j) in the matrix to the value x
void change_elem(matrix* a, size_t i, size_t j, element_t x);

///returns the element in the matrix at position (i,j)
element_t in_index(matrix* a, size_t i, size_t j);



#endif // MATRIX_H_INCLUDED
