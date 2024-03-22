#include "meetingWindow.h"

MeetingWindow::MeetingWindow()
    : AnimationWindow(x, y, w, h, "Tittel") {
        quitBtn.setCallback(std::bind(&MeetingWindow::cb_quit, this));
        add(quitBtn);
    }

void MeetingWindow::cb_quit() {
    AnimationWindow::close();
}