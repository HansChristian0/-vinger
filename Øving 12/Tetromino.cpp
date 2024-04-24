#include "Tetromino.h"
#include <map>
#include <iostream>
    
const std::map<TetrominoType, std::vector<std::vector<int>>> initialMatrixMap {

    {
    TetrominoType::T,
        {
        {0, 0, 0},
        {1, 1, 1},
        {0, 1, 0}
        }
    },
    {
    TetrominoType::J,
        {
        {0, 0, 0},
        {1, 1, 1},
        {0, 0, 1}
        }
    },
    {
    TetrominoType::I,
        {
        {0, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 1},
        }
    },
    {
    TetrominoType::Z,
        {
        {0, 0, 0},
        {1, 1, 0},
        {0, 1, 1}
        }
    },
    {
    TetrominoType::L,
        {
        {0, 0, 0},
        {1, 1, 1},
        {1, 0, 0}
        }
    },
    {
    TetrominoType::S,
        {
        {0, 0, 0},
        {0, 1, 1},
        {1, 1, 0}
        }
    },
    {
    TetrominoType::O,
        {
        {1, 1},
        {1, 1}
        }
    }
};

Tetromino::Tetromino(TDT4102::Point startingPoint, TetrominoType tetType) : 
topLeftCorner{startingPoint}
{
    matrixSize = initialMatrixMap.at(tetType).size();
    //blockMatrix.reserve(matrixSize);
    std::vector<TetrominoType> rowPush;
    for (int row=0; row<matrixSize; row++) {
        //blockMatrix.at(row).reserve(matrixSize);
        rowPush.clear();
        for (int colomn=0; colomn<matrixSize; colomn++) {
            if (initialMatrixMap.at(tetType).at(row).at(colomn) == 1) {
                rowPush.push_back(tetType);
            } else {
                rowPush.push_back(TetrominoType::NONE);
            }
        }
        blockMatrix.push_back(rowPush);
    }
}

Tetromino::Tetromino() {
    topLeftCorner = TDT4102::Point{0,0};
    matrixSize = 0;
}

void Tetromino::rotateCounterClockwise() {
    //Første rotasjon, med hensyn på diagonalen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < row; column++){
            std::swap(blockMatrix[row][column], blockMatrix[column][row]);
        }
    }

    //Andre rotasjon, med hensyn på den midtre raden
    for(int row = 0; row < matrixSize/2; row++){
        for(int column = 0; column < matrixSize; column++){
            std::swap(blockMatrix[row][column], blockMatrix[matrixSize-row-1][column]);
            
        }
    }
}

void Tetromino::rotateClockwise() {
    //Første rotasjon, med hensyn på diagonalen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < row; column++){
            std::swap(blockMatrix[row][column], blockMatrix[column][row]);
        }
    }
     
    //Andre rotasjon, med hensyn på den midtre kolonnen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < matrixSize/2; column++){
            std::swap(blockMatrix[row][column], blockMatrix[row][matrixSize-column-1]);
        }
    }
}

void Tetromino::moveDown() {
    topLeftCorner.y += blockSize;
}
void Tetromino::moveLeft() {
    topLeftCorner.x -= blockSize;
}
void Tetromino::moveRight() {
    topLeftCorner.x += blockSize;
}

bool Tetromino::blockExist(int row, int column) {
    if (blockMatrix.at(row).at(column) == TetrominoType::NONE) {
        return false;
    }
    return true;
}

TetrominoType Tetromino::getBlock(int row, int column) {
    return blockMatrix.at(row).at(column);
}

int Tetromino::getMatrixSize() {
    return matrixSize;
}

TDT4102::Point Tetromino::getPosition() {
    return topLeftCorner;
}