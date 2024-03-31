#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "widgets/TextInput.h" 
#include "widgets/Button.h"
#include "widgets/DropdownList.h"
#include "iostream"
#include "car.h"
#include "person.h"

class MeetingWindow : public AnimationWindow {
private:
static constexpr int x = 100;
static constexpr int y = 100;
static constexpr int w = 1200;
static constexpr int h = 700;
const Point quitBtnPosition {100, 100};
const unsigned int quitBtnWidth = 200;
const unsigned int quitBtnHeight = 40;
const string quitBtnLabel = "Quit!";
TDT4102::Button quitBtn {quitBtnPosition, quitBtnWidth, quitBtnHeight, quitBtnLabel};
const Point personBtnPosition {400, 100};
const unsigned int personBtnWidth = 200;
const unsigned int personBtnHeight = 40;
const string personBtnLabel = "Person!";
TDT4102::Button personBtn {personBtnPosition, personBtnWidth, personBtnHeight, personBtnLabel};
const Point meetingBtnPosition {700, 100};
const unsigned int meetingBtnWidth = 200;
const unsigned int meetingBtnHeight = 40;
const string meetingBtnLabel = "Meeting!";
TDT4102::Button meetingBtn {meetingBtnPosition, meetingBtnWidth, meetingBtnHeight, meetingBtnLabel};

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

const Point dayBtnPosition {100, 150};
const unsigned int dayBtnWidth = 200;
const unsigned int dayBtnHeight = 40;
const string dayBtnLabel = "Dato!";
TDT4102::TextInput dayTxt {dayBtnPosition, dayBtnWidth, dayBtnHeight, dayBtnLabel};
const Point startTimeBtnPosition {100, 200};
const unsigned int startTimeBtnWidth = 200;
const unsigned int startTimeBtnHeight = 40;
const string startTimeBtnLabel = "Starttid";
TDT4102::TextInput startTimeTxt {startTimeBtnPosition, startTimeBtnWidth, startTimeBtnHeight, startTimeBtnLabel};
const Point endTimeBtnPosition {100, 250};
const unsigned int endTimeBtnWidth = 200;
const unsigned int endTimeBtnHeight = 40;
const string endTimeBtnLabel = "Sluttid";
TDT4102::TextInput endTimeTxt {endTimeBtnPosition, endTimeBtnWidth, endTimeBtnHeight, endTimeBtnLabel};
const Point locationDPosition {100, 300};
const int locationDPWidth = 200;
const int locationDPHeight = 40;
std::vector<std::string> optionsLoc {"Trondheim", "Ålesund", "Gjøvik"};
DropdownList locationDP{locationDPosition, locationDPWidth, locationDPHeight, optionsLoc};
const Point subjectBtnPosition {100, 350};
const unsigned int subjectBtnWidth = 200;
const unsigned int subjectBtnHeight = 40;
const string subjectBtnLabel = "Aktivitet";
TDT4102::TextInput subjectTxt {subjectBtnPosition, subjectBtnWidth, subjectBtnHeight, subjectBtnLabel};
const Point leaderDPosition {100, 400};
const int leaderDPWidth = 200;
const int leaderDPHeight = 40;
std::vector<std::string> optionsPers {"###"};
DropdownList leaderDP{leaderDPosition, leaderDPWidth, leaderDPHeight, optionsPers};


public:
    MeetingWindow();

    std::vector<std::shared_ptr<Person>> people;

    void cb_quit();
    void newPerson();
    void showPersonAdding();
    void showMeetingAdding();
};