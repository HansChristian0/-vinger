#include "TetrisWindow.h"
#include <iostream>
#include <random>


TetrisWindow::TetrisWindow(int xPos, int yPos, int width, int height) :
    AnimationWindow{xPos, yPos, width, height}, width{width}, height{height} {
    startPoint = TDT4102::Point{xPos+width/6, yPos+10};
    this->width = width;
    this->height = height;
    generateRandomTetromino();
}

void TetrisWindow::drawCurrentTetromino() {
    for (int row = 0; row<currentTetromino.getMatrixSize(); row++) {
        for (int column = 0; column<currentTetromino.getMatrixSize(); column++) {
            if (currentTetromino.blockExist(row, column)) {
                draw_rectangle(TDT4102::Point{startPoint.x+row*currentTetromino.blockSize, startPoint.y + column*currentTetromino.blockSize}, currentTetromino.blockSize, currentTetromino.blockSize);
            }
        }
    }
}

void TetrisWindow::run() {
    unsigned int framesSinceLastTetronimoMove = 0;
    const unsigned int framesPerTetronimoMove = 20;

    while(!should_close()) { 
        framesSinceLastTetronimoMove++;
        if(framesSinceLastTetronimoMove >= framesPerTetronimoMove) {
            framesSinceLastTetronimoMove = 0;
            /********************************************************/

            /********************************************************/
        }
        handleInput();
        
        /********************************************************/
        drawCurrentTetromino();
        /********************************************************/

        next_frame();
    }
}

void TetrisWindow::generateRandomTetromino() {
    std::random_device rd;
    std::uniform_int_distribution<int> distr(0,6);
    std::default_random_engine generator(rd());
    int randomNumber = distr(generator);

    currentTetromino = Tetromino{startPoint, static_cast<TetrominoType>(randomNumber)};
}

void TetrisWindow::handleInput() {

    static bool lastZKeyState = false;
    static bool lastUpKeyState = false;

    bool currentZKeyState = is_key_down(KeyboardKey::Z);
    bool currentUpKeyState = is_key_down(KeyboardKey::UP);

    
    if(currentZKeyState && !lastZKeyState) {
        std::cout << "Hello from z\n";
    }

    if(currentUpKeyState && !lastUpKeyState) {
        std::cout << "Hello from up\n";
    }


    lastZKeyState = currentZKeyState;
    lastUpKeyState = currentUpKeyState;
}

