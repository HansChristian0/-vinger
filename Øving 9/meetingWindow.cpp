#include "meetingWindow.h"
#include "iostream"
#include "person.h"

MeetingWindow::MeetingWindow()
    : AnimationWindow(x, y, w, h, "Tittel") {
        quitBtn.setCallback(std::bind(&MeetingWindow::cb_quit, this));
        add(quitBtn);
        personBtn.setCallback(std::bind(&MeetingWindow::showPersonAdding, this));
        add(personBtn);
        meetingBtn.setCallback(std::bind(&MeetingWindow::showMeetingAdding, this));
        add(meetingBtn);

        string a = nameTxt.getText();
        add(nameTxt);
        add(emailTxt);
        add(personSeatsTxt);
        addBtn.setCallback(std::bind(&MeetingWindow::newPerson, this));
        add(addBtn);
        add(dayTxt);
        add(startTimeTxt);
        add(endTimeTxt);
        add(locationDP);
        add(subjectTxt);
        add(leaderDP);


        nameTxt.setVisible(false);
        emailTxt.setVisible(false);
        personSeatsTxt.setVisible(false);
        addBtn.setVisible(false);
        dayTxt.setVisible(false);
        startTimeTxt.setVisible(false);
        endTimeTxt.setVisible(false);
        locationDP.setVisible(false);
        subjectTxt.setVisible(false);
        leaderDP.setVisible(false);
    }

void MeetingWindow::cb_quit() {
    AnimationWindow::close();
}

void MeetingWindow::newPerson() {
    if (stoi(personSeatsTxt.getText()) > 0) {
        MeetingWindow::people.emplace_back(new Person(nameTxt.getText(), emailTxt.getText(), std::make_unique<Car>(stoi(personSeatsTxt.getText()))));
    } else {
         MeetingWindow::people.emplace_back(new Person(nameTxt.getText(), emailTxt.getText()));
    } 
    nameTxt.setText("");
    emailTxt.setText("");
    personSeatsTxt.setText("");
    for (std::shared_ptr<Person>& person : people) {
        cout << person;
    }
}

void MeetingWindow::showPersonAdding() {
    dayTxt.setVisible(false);
    startTimeTxt.setVisible(false);
    endTimeTxt.setVisible(false);
    locationDP.setVisible(false);
    subjectTxt.setVisible(false);
    leaderDP.setVisible(false);
    nameTxt.setVisible(true);
    emailTxt.setVisible(true);
    personSeatsTxt.setVisible(true);
    addBtn.setVisible(true);
}
void MeetingWindow::showMeetingAdding() {
    if (people.size() > 0) {
        std::vector<std::string> options;
        for (std::shared_ptr<Person>& navn : people) {
            options.push_back(navn->getName());
        }
        leaderDP.setOptions(options);
    }
    dayTxt.setVisible(true);
    startTimeTxt.setVisible(true);
    endTimeTxt.setVisible(true);
    locationDP.setVisible(true);
    subjectTxt.setVisible(true);
    leaderDP.setVisible(true);
    nameTxt.setVisible(false);
    emailTxt.setVisible(false);
    personSeatsTxt.setVisible(false);
    addBtn.setVisible(false);
}