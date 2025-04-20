#include "Matrix.h"
#include <iostream>

int main() {
    Matrix A = {
        {6, 4},
        {8, 3}
    };

    Matrix B = {
        {1, 2, 3},
        {4, 5, 6}
    };

    Matrix C = {
        {2, 4, 6},
        {1, 3, 5}
    };

    Matrix D = A + (B * 3) * C.transpose();

    std::cout << "D = A + (3 * B) x C^T:" << std::endl;
    D.print();

    return 0;
}
