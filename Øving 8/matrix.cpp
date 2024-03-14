#include "matrix.h"
#include "iostream"
#include "cassert"

Matrix::Matrix(int nRows, int nColmns) : rows{nRows}, columns{nColmns} {
    assert(nColmns>0 && nRows>0);
    matrix = new double[nRows*nColmns];
    for (int i=0; i<nRows*nColmns; i++) {
        matrix[i] = 0;
    }
}

Matrix::Matrix(int nRows) : rows{nRows}, columns{nRows} {
    assert(nRows>0);
    matrix = new double[nRows*nRows];
    int i = 0;
    for (int row=0; row<nRows; row++) {
        for (int column=0; column<nRows; column++) {
            if (row==column){
                matrix[i] = 1;
            } else{
                matrix[i] = 0;
            }
            i++;
        }
    }
}

Matrix::~Matrix() {
    delete[] matrix;
    std::cout << "Matrix is destructed" << std::endl;
}

double Matrix::get(int row, int col) {
    return matrix[(row-1)*columns+col-1];
}

void Matrix::set(int row, int col, double value) {
    matrix[(row-1)*columns+col-1] = value;
}
int Matrix::getRows() {
    return rows;
}

int Matrix::getColumns(){
    return columns;
}

std::ostream& operator<<(std::ostream& os, Matrix* matrixToPrint) {
    int i = 0;
    for (int row=0; row<matrixToPrint->rows; row++) {
        for (int column=0; column<matrixToPrint->columns; column++) {
            os << matrixToPrint->matrix[i] << "  ";
            i++;
        }
        os << std::endl;
    }
    return os;
}