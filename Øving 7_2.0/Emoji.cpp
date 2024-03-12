#include "Emoji.h"
#include "AnimationWindow.h"


Face::Face(Point centre, int radius) 
    : centre{centre}, radius{radius} {};

void Face::draw(AnimationWindow& win) {
    win.draw_circle(Face::centre, Face::radius, Color::orange_red);
};

EmptyFace::EmptyFace(Point centre, int radius)
    : Face(centre, radius), 
    leftEye{Point{EmptyFace::centre.x-radius/2, EmptyFace::centre.y-radius/3}}, 
    rightEye{Point{EmptyFace::centre.x+radius/2, EmptyFace::centre.y-radius/3}}, 
    radiusEye{radius/4} {};

void EmptyFace::draw(AnimationWindow& win) {
    Face::draw(win);
    win.draw_circle(EmptyFace::leftEye, EmptyFace::radiusEye, Color::aqua);
    win.draw_circle(EmptyFace::rightEye, EmptyFace::radiusEye, Color::aqua);
}
    
SintFace::SintFace(Point centre, int radius)
    : Face(centre, radius),
    leftEye{Point{SintFace::centre.x - radius / 3, SintFace::centre.y - radius / 3}},
    rightEye{Point{SintFace::centre.x + radius / 3, SintFace::centre.y - radius / 3}},
    radiusEye{radius / 4} {};

void SintFace::draw(AnimationWindow& win) {
    Face::draw(win);
    win.draw_circle(SintFace::leftEye, SintFace::radiusEye, Color::red);
    win.draw_circle(SintFace::rightEye, SintFace::radiusEye, Color::red);
}

OverrasketFace::OverrasketFace(Point centre, int radius)
    : Face(centre, radius),
    leftEye{Point{OverrasketFace::centre.x - radius / 3, OverrasketFace::centre.y - radius / 3}},
    rightEye{Point{OverrasketFace::centre.x + radius / 3, OverrasketFace::centre.y - radius / 3}},
    radiusEye{radius / 3} {};

void OverrasketFace::draw(AnimationWindow& win) {
    Face::draw(win);
    win.draw_circle(OverrasketFace::leftEye, OverrasketFace::radiusEye, Color::yellow);
    win.draw_circle(OverrasketFace::rightEye, OverrasketFace::radiusEye, Color::yellow);
}