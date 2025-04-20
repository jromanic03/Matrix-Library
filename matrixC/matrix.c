#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix create_matrix(int rows, int cols) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; ++i)
        m.data[i] = (int*)calloc(cols, sizeof(int));
    return m;
}

void free_matrix(Matrix* m) {
    for (int i = 0; i < m->rows; ++i)
        free(m->data[i]);
    free(m->data);
    m->data = NULL;
    m->rows = m->cols = 0;
}

void print_matrix(const Matrix* m) {
    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->cols; ++j)
            printf("%d ", m->data[i][j]);
        printf("\n");
    }
}

Matrix add_matrices(const Matrix* a, const Matrix* b) {
    Matrix result = create_matrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; ++i)
        for (int j = 0; j < a->cols; ++j)
            result.data[i][j] = a->data[i][j] + b->data[i][j];
    return result;
}

Matrix scalar_multiply(const Matrix* m, int scalar) {
    Matrix result = create_matrix(m->rows, m->cols);
    for (int i = 0; i < m->rows; ++i)
        for (int j = 0; j < m->cols; ++j)
            result.data[i][j] = m->data[i][j] * scalar;
    return result;
}

Matrix multiply_matrices(const Matrix* a, const Matrix* b) {
    Matrix result = create_matrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; ++i) {
        for (int j = 0; j < b->cols; ++j) {
            for (int k = 0; k < a->cols; ++k)
                result.data[i][j] += a->data[i][k] * b->data[k][j];
        }
    }
    return result;
}

Matrix transpose_matrix(const Matrix* m) {
    Matrix result = create_matrix(m->cols, m->rows);
    for (int i = 0; i < m->rows; ++i)
        for (int j = 0; j < m->cols; ++j)
            result.data[j][i] = m->data[i][j];
    return result;
}
