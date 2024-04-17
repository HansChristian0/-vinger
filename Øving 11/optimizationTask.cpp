#include "Stopwatch.h"
#include <vector>
#include <iostream>

// Utdelt kode til oppgave 3

void setDiagonalValue(std::vector<std::vector<double>>& matrix, double newValue){
    for (int row = 0; row < matrix.size(); row++){
        matrix.at(row).at(row) = newValue;
    }
}

double sumMatrix(std::vector<std::vector<double>> matrix){
 double sum;
    for (int i = 0; i < matrix.size()*matrix.size(); i++){
        double value = matrix.at(int(i/matrix.size())).at(i-matrix.size()*int(i/matrix.size()));
        sum += value;
    }
    return sum;
}

void optimizationTask() {
    
    const int matrixSize = 10000;

    // Create a matrix with zeros
    std::vector<std::vector<double>> matrix;
    std::vector<double> column;
    column.resize(matrixSize);
    for (int i = 0; i < matrixSize; i++){
        matrix.push_back(column);
    }

    // Set all elements on the diagonal to 0.41
    setDiagonalValue(matrix, 0.41);
    
    // Sum all elements in the matrix
    double total = sumMatrix(matrix);

    double coolerNumber = total + 2;
    std::cout << "TDT" << coolerNumber << std::endl;
}