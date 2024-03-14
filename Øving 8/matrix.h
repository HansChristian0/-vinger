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
    Matrix& operator=(const Matrix& matrix);

    double get(int row, int col);
    void set(int row, int col, double value);
    int getRows();
    int getColumns();
    
    friend std::ostream& operator<<(std::ostream& os, Matrix* matrixToPrint);
};
