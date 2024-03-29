#include "meetingWindow.h"

MeetingWindow::MeetingWindow()
    : AnimationWindow(x, y, w, h, "Tittel") {
        quitBtn.setCallback(std::bind(&MeetingWindow::cb_quit, this));
        string a = nameTxt.getText();
        add(quitBtn);
        add(nameTxt);
        add(emailTxt);
        add(personSeatsTxt);
        addBtn.setCallback(std::bind(&MeetingWindow::newPerson, this));
        add(addBtn);
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