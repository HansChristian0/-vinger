#pragma once
#include "iostream"
#include "memory"
#include "car.h"

class Person {
private:
    std::string name;
    std::string email;

public:
    std::unique_ptr<Car> car;

    Person(std::string name, std::string email, std::unique_ptr<Car> car = nullptr);

    void setEmail(std::string email);    
    std::string getName();
    std::string getEmail();
    bool hasAvailableSeats();

    const friend std::ostream& operator<<(std::ostream& os, Person* person);
};