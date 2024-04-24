#pragma once
#include "AnimationWindow.h"
#include "Tetromino.h"
#include "widgets/TextInput.h"
#include "widgets/Button.h"

class TetrisWindow : public TDT4102::AnimationWindow {

public:
    TetrisWindow(int xPos, int yPos, int width, int height);
    void run();
    std::vector<std::vector<TetrominoType>> gridMatrix;
    Tetromino currentTetromino;

    void generateRandomTetromino();
    void drawCurrentTetromino();

private:
    int height;
    int width;
    TDT4102::Point startPoint;
    int blocksize;
    void handleInput();

};