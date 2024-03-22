#include "meeting.h"
#include "iostream"
#include "person.h"
#include "string"

std::ostream& operator<<(std::ostream& os, Campus* campus) {

    switch (*campus)
    {
    case Campus::Trondheim:
        os << "Trondheim";
        break;
    case Campus::Ålesund:
        os << "Ålesund";
        break;
    case Campus::Gjøvik:
        os << "Gjøvik";
        break;
    default:
        break;
    }
    os << std::endl;

    return os;
}

std::ostream& operator<<(std::ostream& os, Meeting* møte) {
    os << "Klokka " << møte->getStartTime() << " til " << møte->getEndTime() << std::endl 
    << "Aktivitet: " << møte->getSubject() << " sammen med " << møte->getLeader() << std::endl
    << "Lokasjon: " << møte->getLocation() << std::endl 
    << "Deltagere er: ";
    std::vector<std::string> navn = møte->getParticipantList();
    for (std::string deltager : møte->getParticipantList()) {
        os << std::endl << deltager;
    }
    os << std::endl;
    return os;
}

Meeting::Meeting(int day, int startTime, int endTime, Campus location, std::string subject, std::shared_ptr<Person> leader)
: leader{leader} {
    this->day = day;
    this->startTime = startTime;
    this->endTime = endTime;
    this->location = location;
    this->subject = subject;
    addParticipant(leader);
}

int Meeting::getDay()
{
    return this->day;
}
int Meeting::getStartTime() {
    return this->startTime;
}
int Meeting::getEndTime() {
    return this->endTime;
}
std::string Meeting::getLocation() {
    switch (location)
    {
    case Campus::Trondheim:
        return "Trondheim";
    case Campus::Ålesund:
        return "Ålesund";
    case Campus::Gjøvik:
        return "Gjøvik";
    default:
        return NULL;
    }
}
std::string Meeting::getSubject() {
    return subject;
}
std::string Meeting::getLeader() {
    return leader->getName();
}

std::vector<std::string> Meeting::getParticipantList() {
    std::vector<std::string> deltagereString;
    for (std::shared_ptr<Person>& person : this->participants) {
        deltagereString.push_back(person->getName());
    }
    return deltagereString;
}

void Meeting::addParticipant(std::shared_ptr<Person> person) {
    participants.push_back(person);
}

std::vector<std::shared_ptr<Person>> Meeting::findPotentialCoDriver(Meeting* anotherMeeting) {
    std::vector<std::shared_ptr<Person>> ledigeBiler;
    if (this->location == anotherMeeting->location && this->day == anotherMeeting->day && 
    abs(this->startTime-anotherMeeting->startTime)<=1 && abs(this->endTime-anotherMeeting->endTime) <=1) {
        for (std::shared_ptr<Person>& deltaker : anotherMeeting->participants) {
            if (deltaker->hasAvailableSeats()) {
                ledigeBiler.push_back(deltaker);
            }
        }
    }
    return ledigeBiler;
}