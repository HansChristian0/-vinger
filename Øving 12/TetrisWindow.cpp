#include "TetrisWindow.h"
#include <iostream>
#include <random>


TetrisWindow::TetrisWindow(int xPos, int yPos, int width, int height) :
    AnimationWindow{xPos, yPos, width, height}, width{width}, height{height} {
    startPoint = TDT4102::Point{xPos+width/6, yPos+10};
    this->width = width;
    this->height = height;
    windowPoint = TDT4102::Point{xPos, yPos};
    generateRandomTetromino();
}

void TetrisWindow::drawCurrentTetromino() {
    for (int row = 0; row<currentTetromino.getMatrixSize(); row++) {
        for (int column = 0; column<currentTetromino.getMatrixSize(); column++) {
            if (currentTetromino.blockExist(row, column)) {
                draw_rectangle(TDT4102::Point{currentTetromino.getPosition().x+row*currentTetromino.blockSize, currentTetromino.getPosition().y + column*currentTetromino.blockSize}, currentTetromino.blockSize, currentTetromino.blockSize);
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
            moveTetrominoDown();
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

void TetrisWindow::moveTetrominoDown() {
    if (currentTetromino.getPosition().y < height- 5*currentTetromino.blockSize) {
        currentTetromino.moveDown();
    }
}

void TetrisWindow::handleInput() {

    static bool lastZKeyState = false;
    static bool lastUpKeyState = false;
    static bool lastLeftKeyState = false;
    static bool lastRightKeyState = false;
    static bool lastDownKeyState = false;

    bool currentZKeyState = is_key_down(KeyboardKey::Z);
    bool currentUpKeyState = is_key_down(KeyboardKey::UP);
    bool currentLeftKeyState = is_key_down(KeyboardKey::LEFT);
    bool currentRightKeyState = is_key_down(KeyboardKey::RIGHT);
    bool currentDownKeyState = is_key_down(KeyboardKey::DOWN);

    
    if(currentZKeyState && !lastZKeyState) {
        currentTetromino.rotateCounterClockwise();
    }

    if(currentUpKeyState && !lastUpKeyState) {
        currentTetromino.rotateClockwise();
    }
    if(currentLeftKeyState && !lastLeftKeyState) {
        if (currentTetromino.getPosition().x > 5*currentTetromino.blockSize) {
            currentTetromino.moveLeft();
        }
    }
    if(currentRightKeyState && !lastRightKeyState) {
        if (currentTetromino.getPosition().x < width-9*currentTetromino.blockSize) {
            currentTetromino.moveRight();
        }
    }
    if(currentDownKeyState && !lastDownKeyState) {
        if (currentTetromino.getPosition().y < height- 5*currentTetromino.blockSize) {
            currentTetromino.moveDown();
        }
    }


    lastZKeyState = currentZKeyState;
    lastUpKeyState = currentUpKeyState;
    lastLeftKeyState = currentLeftKeyState;
    lastRightKeyState = currentRightKeyState;
    lastDownKeyState = currentDownKeyState;
}

