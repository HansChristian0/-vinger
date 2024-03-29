#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "widgets/TextInput.h" 
#include "widgets/Button.h"
#include "iostream"
#include "car.h"
#include "person.h"

class MeetingWindow : public AnimationWindow {
private:
static constexpr int x = 100;
static constexpr int y = 100;
static constexpr int w = 800;
static constexpr int h = 700;
const Point quitBtnPosition {100, 100};
const unsigned int quitBtnWidth = 200;
const unsigned int quitBtnHeight = 40;
const string quitBtnLabel = "Quit!";
TDT4102::Button quitBtn {quitBtnPosition, quitBtnWidth, quitBtnHeight, quitBtnLabel};
const Point nameBtnPosition {100, 150};
const unsigned int nameBtnWidth = 200;
const unsigned int nameBtnHeight = 40;
const string nameBtnLabel = "Name!";
TDT4102::TextInput nameTxt {nameBtnPosition, nameBtnWidth, nameBtnHeight, nameBtnLabel};
const Point emailBtnPosition {100, 200};
const unsigned int emailBtnWidth = 200;
const unsigned int emailBtnHeight = 40;
const string emailBtnLabel = "E-mail!";
TDT4102::TextInput emailTxt {emailBtnPosition, emailBtnWidth, emailBtnHeight, emailBtnLabel};
const Point personSeatsBtnPosition {100, 250};
const unsigned int personSeatsBtnWidth = 200;
const unsigned int personSeatsBtnHeight = 40;
const string personSeatsBtnLabel = "Ledige seter";
TDT4102::TextInput personSeatsTxt {personSeatsBtnPosition, personSeatsBtnWidth, personSeatsBtnHeight, personSeatsBtnLabel};
const Point addBtnPosition {100, 300};
const unsigned int addBtnWidth = 200;
const unsigned int addBtnHeight = 40;
const string addBtnLabel = "Add person!";
TDT4102::Button addBtn {addBtnPosition, addBtnWidth, addBtnHeight, addBtnLabel};

public:
    MeetingWindow();

    std::vector<std::shared_ptr<Person>> people;

    void cb_quit();
    void newPerson();
};