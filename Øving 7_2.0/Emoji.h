#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"

// Abstrakt klasse. Arvende konkrete klasser må implementere funksjonen draw()
// som tegner former i vinduet de skal bli vist i.

class Emoji
{
public:
    virtual void draw(AnimationWindow& win) = 0;
    virtual ~Emoji(){}; //destruktør
};

class Face : public Emoji {
public:
    virtual void draw(AnimationWindow& win) = 0;
    Point centre;
    int radius;

    Face(Point centre, int radius); 
};

class EmptyFace : public Face {
public:
    Point leftEye;
    Point rightEye;
    int radiusEye;
    EmptyFace(Point centre, int radius);
    void draw(AnimationWindow& win) override;
};

class SintFace : public Face {
public:
    Point leftEye;
    Point rightEye;
    int radiusEye;
    SintFace(Point centre, int radius);
    void draw(AnimationWindow& win) override;
};

class OverrasketFace : public Face {
public:
    Point leftEye;
    Point rightEye;
    int radiusEye;
    OverrasketFace(Point centre, int radius);
    void draw(AnimationWindow& win) override;
};