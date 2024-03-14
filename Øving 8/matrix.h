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

    double get(int row, int col);
    void set(int row, int col, double value);
    int getRows();
    int getColumns();
    
    friend std::ostream& operator<<(std::ostream& os, Matrix* matrixToPrint);
};
