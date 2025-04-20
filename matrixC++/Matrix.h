#pragma once
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data;

public:
    Matrix(int rows, int cols);
    Matrix(std::initializer_list<std::initializer_list<int>> init);

    int rows() const;
    int cols() const;
    int& at(int i, int j);
    int at(int i, int j) const;

    Matrix operator+(const Matrix& other) const;
    Matrix operator*(int scalar) const;
    Matrix operator*(const Matrix& other) const;
    Matrix transpose() const;

    void print() const;
};
