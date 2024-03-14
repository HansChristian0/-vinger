#pragma once
#include "iostream"
#include "vector"
#include "iostream"

class Matrix {
public:
    int rows;
    int columns;
    double *matrix;

    Matrix(int nRows, int nColumns);
    explicit Matrix(int nRows);
    ~Matrix();

    Matrix(const Matrix& rhs);

    double get(int row, int col);
    void set(int row, int col, double value);
    int getRows();
    int getColumns();
    
    friend std::ostream& operator<<(std::ostream& os, Matrix* matrixToPrint);
    Matrix& operator=(const Matrix& matrix);
    Matrix& operator+=(const Matrix& otherMatrix);
    friend Matrix& operator+(Matrix& lhs, Matrix& rhs);
    Matrix& operator-=(const Matrix& otherMatrix);
    friend Matrix& operator-(Matrix& lhs, Matrix& rhs);
    Matrix& operator*=(const Matrix& otherMatrix);
    friend Matrix& operator*(Matrix& lhs, Matrix& rhs);
};
