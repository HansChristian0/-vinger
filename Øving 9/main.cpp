#include "car.h"
#include "iostream"
#include "person.h"
#include "meeting.h"

int main() {
    Campus NTNU = Campus::Trondheim;
    std::unique_ptr<Car> car = std::make_unique<Car>(2);
    std::shared_ptr<Person> Per = std::make_shared<Person>("Per", "gmail.com");
    Meeting lek(4, 16, 20, NTNU, "Lek og morro", Per);
    std::shared_ptr<Person> Ferdinand = std::make_shared<Person>("Ferdiand", "gmail.com", nullptr);
    std::shared_ptr<Person> Meg = std::make_shared<Person>("meg", "gmail.com", nullptr);
    lek.addParticipant(Ferdinand);
    lek.addParticipant(Meg);
    std::cout << &lek;

    return 0;
}