#pragma once
#include "ostream"
#include "iostream"
#include "vector"
#include "memory"
#include "person.h"

enum class Campus {
    Trondheim,
    Ålesund,
    Gjøvik
};
std::ostream& operator<<(std::ostream& os, Campus* campus);

class Meeting {
private:
    int day;
    int startTime;
    int endTime;
    Campus location;
    std::string subject;
    const std::shared_ptr<Person> leader;
    std::vector<std::shared_ptr<Person>> participants;

public:
    Meeting(int day, int startTime, int endTime, Campus location, std::string subject, std::shared_ptr<Person> leader);

    int getDay();
    int getStartTime();
    int getEndTime();
    std::string getLocation();
    std::string getSubject();
    std::string getLeader();
    std::vector<std::string> getParticipantList();

    void addParticipant(std::shared_ptr<Person> person);
};