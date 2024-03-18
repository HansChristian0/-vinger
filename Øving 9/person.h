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
};