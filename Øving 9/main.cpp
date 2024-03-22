#include "car.h"
#include "iostream"
#include "person.h"
#include "meeting.h"

int main() {
    Campus NTNU = Campus::Trondheim;
    Campus Ålesund = Campus::Ålesund;
    std::shared_ptr<Person> Per = std::make_shared<Person>("Per", "gmail.com");
    Meeting lek(4, 16, 20, NTNU, "Lek og morro", Per);
    std::shared_ptr<Person> Ferdinand = std::make_shared<Person>("Ferdiand", "gmail.com", std::make_unique<Car>(2));
    std::shared_ptr<Person> Meg = std::make_shared<Person>("meg", "gmail.com", nullptr);
    lek.addParticipant(Ferdinand);
    lek.addParticipant(Meg);
    std::cout << Meg;
    std::cout << &lek;

    Meeting lek2(4, 17, 21, Ålesund, "Lek og morro", Per);
    auto a = lek2.findPotentialCoDriver(&lek);

    return 0;
}