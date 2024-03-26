#include "meetingWindow.h"

MeetingWindow::MeetingWindow()
    : AnimationWindow(x, y, w, h, "Tittel") {
        quitBtn.setCallback(std::bind(&MeetingWindow::cb_quit, this));
        nameTxt.getText();
        add(quitBtn);
        add(nameTxt);
        add(emailTxt);
        add(personSeatsTxt);
    }

void MeetingWindow::cb_quit() {
    AnimationWindow::close();
}