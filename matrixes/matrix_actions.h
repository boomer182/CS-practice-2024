#ifndef MATRIX_ACTIONS_H_INCLUDED
#define MATRIX_ACTIONS_H_INCLUDED

typedef struct matrix matrix;
typedef double element_t;
struct matrix;

///adding two matrices(a and b) the result - the third matrix c
matrix* adding(matrix* a, matrix* b);


///swap elements a and b
void element_swap(element_t* a, element_t* b);

///transposes matrix a and stores the result in matrix b
matrix* transpose(matrix* a, matrix* b);

///transpose matrix a
matrix* self_transpose(matrix* a);


///multiplying two matrices
matrix* matrix_multipl(matrix* a, matrix* b, matrix* c);

///multiplying matrix by number
matrix* number_multipl(matrix* a, element_t b);


///swap two strings in matrix
void swap_strings(matrix* a, size_t x, size_t y);

///subtracts from the row x of the matrix a the row y multiplied by the number c
void minus_str(matrix* a, size_t x, size_t y, element_t c);

///multiplies row x of matrix a by number c
void multipl_str(matrix* a, size_t x, element_t c);

///prints the given matrix
void matrix_print(struct matrix* a);

///function computes the matrix exponential of the given matrix a up to a given precision eps
matrix* matrix_exp(matrix* a, element_t eps);

///function calculates the norm of a matrix a.
element_t matrix_norm(matrix* a);

///this function performs Gaussian elimination on the matrix a
matrix* gauss (matrix* a);

#endif // MATRIX_ACTIONS_H_INCLUDED
