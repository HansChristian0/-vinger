#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"

struct Config {
    int colorUp;
    int colorDown;
    int speed;
};

void bouncingBall();
map<int, Color> returnIntToColor();
istream& operator>>(istream& is, Config& cfg);

