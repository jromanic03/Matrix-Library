#include "Matrix.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Matrix::Matrix(int rows, int cols) : data(rows, vector<int>(cols)) {}

Matrix::Matrix(initializer_list<initializer_list<int>> init) {
    for (const auto& row : init)
        data.emplace_back(row);
}

int Matrix::rows() const { return data.size(); }
int Matrix::cols() const { return data[0].size(); }

int& Matrix::at(int i, int j) { return data[i][j]; }
int Matrix::at(int i, int j) const { return data[i][j]; }

Matrix Matrix::operator+(const Matrix& other) const {
    if (rows() != other.rows() || cols() != other.cols())
        throw runtime_error("Matrix dimensions must match for addition.");
    Matrix result(rows(), cols());
    for (int i = 0; i < rows(); ++i)
        for (int j = 0; j < cols(); ++j)
            result.at(i, j) = at(i, j) + other.at(i, j);
    return result;
}

Matrix Matrix::operator*(int scalar) const {
    Matrix result(rows(), cols());
    for (int i = 0; i < rows(); ++i)
        for (int j = 0; j < cols(); ++j)
            result.at(i, j) = at(i, j) * scalar;
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols() != other.rows())
        throw runtime_error("Invalid matrix dimensions for multiplication.");
    Matrix result(rows(), other.cols());
    for (int i = 0; i < result.rows(); ++i)
        for (int j = 0; j < result.cols(); ++j) {
            int sum = 0;
            for (int k = 0; k < cols(); ++k)
                sum += at(i, k) * other.at(k, j);
            result.at(i, j) = sum;
        }
    return result;
}

Matrix Matrix::transpose() const {
    Matrix result(cols(), rows());
    for (int i = 0; i < rows(); ++i)
        for (int j = 0; j < cols(); ++j)
            result.at(j, i) = at(i, j);
    return result;
}

void Matrix::print() const {
    for (const auto& row : data) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }
}
