#include <stdio.h>
#include "matrix.h"

void fill_matrix(Matrix* m, int values[][10]) {
    for (int i = 0; i < m->rows; ++i)
        for (int j = 0; j < m->cols; ++j)
            m->data[i][j] = values[i][j];
}

int main() {
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(2, 3);
    Matrix C = create_matrix(2, 3);

    int a_vals[2][10] = {{6, 4}, {8, 3}};
    int b_vals[2][10] = {{1, 2, 3}, {4, 5, 6}};
    int c_vals[2][10] = {{2, 4, 6}, {1, 3, 5}};

    fill_matrix(&A, a_vals);
    fill_matrix(&B, b_vals);
    fill_matrix(&C, c_vals);

    Matrix B3 = scalar_multiply(&B, 3);
    Matrix CT = transpose_matrix(&C);
    Matrix product = multiply_matrices(&B3, &CT);
    Matrix D = add_matrices(&A, &product);

    printf("D = A + (3 * B) x C^T:\n");
    print_matrix(&D);

    // Cleanup
    free_matrix(&A);
    free_matrix(&B);
    free_matrix(&C);
    free_matrix(&B3);
    free_matrix(&CT);
    free_matrix(&product);
    free_matrix(&D);

    return 0;
}
