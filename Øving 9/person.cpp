#include "person.h"
#include "iostream"
#include "car.h"
#include "memory"

Person::Person(std::string name, std::string email, std::unique_ptr<Car> car) {
    this->name = name;
    this->email = email;
    this->car = std::move(car);
}

void Person::setEmail(std::string email) {
    this->email = email;
}

std::string Person::getName() {
    return name;
}

std::string Person::getEmail() {
    return email;
}

bool Person::hasAvailableSeats() {
    if (this->car != nullptr) {
        if (this->car.get()->hasFreeSeats()) {
            return true;
        }
    }
    return false;
}

const std::ostream& operator<<(std::ostream& os, std::shared_ptr<Person> person) {
    if (person->car != nullptr){
        os << person->getName() << " (" << person->getEmail() << ")" << " har bilplass." << std::endl;
    } else {
        os << person->getName() << " (" << person->getEmail() << ")" << " har ikke bilplass." << std::endl;
    }

    return os;
}