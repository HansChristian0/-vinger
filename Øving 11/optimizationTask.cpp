#include "Stopwatch.h"
#include <vector>
#include <iostream>

// Utdelt kode til oppgave 3

void setDiagonalValue(std::vector<std::vector<float>>& matrix, float newValue){
    
    for (int row = 0; row < matrix.size(); row++) {
        matrix.at(row).at(row) = newValue;
    }
}

double sumMatrix(std::vector<std::vector<float>> matrix){
    double sum;
    for (int i = 0; i < std::pow(matrix.size(), 2); i++){
        sum += matrix.at(int(i/matrix.size())).at(i-matrix.size()*int(i/matrix.size()));
    }
    return sum;
}

void optimizationTask() {
    
    const int matrixSize = 10000;

    // Create a matrix with zeros
    std::vector<std::vector<float>> matrix;
    std::vector<float> column;
    column.resize(matrixSize);
    matrix.reserve(matrixSize);
    for (int i = 0; i < matrixSize; i++){
        matrix.push_back(column);
    }

    // Set all elements on the diagonal to 0.41
    setDiagonalValue(matrix, 0.41);
    
    // Sum all elements in the matrix
    float total = sumMatrix(matrix);

    float coolerNumber = total + 2;
    std::cout << "TDT" << coolerNumber << std::endl;
}