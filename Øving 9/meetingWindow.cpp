#include "meetingWindow.h"
#include "iostream"
#include "person.h"
#include "meeting.h"

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
        addMeetingBtn.setCallback(std::bind(&MeetingWindow::addMeeting, this));
        add(addMeetingBtn);

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
        addMeetingBtn.setVisible(false);
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

void MeetingWindow::addMeeting() {
    Campus campus;
    if (locationDP.getValue() == "Trondheim") {
        campus = Campus::Trondheim;
    } else if (locationDP.getValue() == "Ålesund") {
        campus = Campus::Ålesund;
    } else if (locationDP.getValue() == "Gjøvik") {
        campus = Campus::Gjøvik;
    }
    std::shared_ptr<Person> leder;
    for (std::shared_ptr<Person>& leder : people) {
        if (leder->getEmail() == leaderDP.getValue()) {
            meetings.emplace_back(new Meeting(stoi(dayTxt.getText()), stoi(startTimeTxt.getText()), stoi(endTimeTxt.getText()), campus, subjectTxt.getText(), leder));
            break;
        }   
    }
    for (std::shared_ptr<Meeting>& møte : meetings) {
        std::cout << møte;
    }
}

void MeetingWindow::showPersonAdding() {
    dayTxt.setVisible(false);
    startTimeTxt.setVisible(false);
    endTimeTxt.setVisible(false);
    locationDP.setVisible(false);
    subjectTxt.setVisible(false);
    leaderDP.setVisible(false);
    addMeetingBtn.setVisible(false);
    nameTxt.setVisible(true);
    emailTxt.setVisible(true);
    personSeatsTxt.setVisible(true);
    addBtn.setVisible(true);
}
void MeetingWindow::showMeetingAdding() {
    if (people.size() > 0) {
        std::vector<std::string> options;
        for (std::shared_ptr<Person>& navn : people) {
            options.push_back(navn->getEmail());
        }
        leaderDP.setOptions(options);
    }
    dayTxt.setVisible(true);
    startTimeTxt.setVisible(true);
    endTimeTxt.setVisible(true);
    locationDP.setVisible(true);
    subjectTxt.setVisible(true);
    leaderDP.setVisible(true);
    addMeetingBtn.setVisible(true);
    nameTxt.setVisible(false);
    emailTxt.setVisible(false);
    personSeatsTxt.setVisible(false);
    addBtn.setVisible(false);
}