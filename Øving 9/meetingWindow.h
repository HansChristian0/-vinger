#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "widgets/TextInput.h" 
#include "widgets/Button.h"
#include "iostream"

class MeetingWindow : public AnimationWindow {
private:
static constexpr int x = 100;
static constexpr int y = 100;
static constexpr int w = 800;
static constexpr int h = 700;
        const Point buttonPosition {100, 100};
        const unsigned int buttonWidth = 100;
        const unsigned int buttonHeight = 40;
        const string buttonLabel = "Click me!";
TDT4102::Button quitBtn {buttonPosition, buttonWidth, buttonHeight, buttonLabel};

public:
    MeetingWindow();

    void cb_quit();
};