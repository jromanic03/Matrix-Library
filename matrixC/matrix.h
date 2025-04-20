#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    int rows;
    int cols;
    int** data;
} Matrix;

Matrix create_matrix(int rows, int cols);
void free_matrix(Matrix* m);
void print_matrix(const Matrix* m);
Matrix add_matrices(const Matrix* a, const Matrix* b);
Matrix scalar_multiply(const Matrix* m, int scalar);
Matrix multiply_matrices(const Matrix* a, const Matrix* b);
Matrix transpose_matrix(const Matrix* m);

#endif
