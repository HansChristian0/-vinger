#include "animal.h"
#include "std_lib_facilities.h"

Animal::Animal(string name, int age)
    : name{name}, age{age} {}

Animal::~Animal() {
    cout << "Destructor executed" << endl;
}

string Animal::toString() {
    stringstream returnStream;
    returnStream << "Animal: " << name << ", " << age;
    return returnStream.str();
}


Cat::Cat(string name, int age)
    : Animal(name, age) {}

string Cat::toString() {
    stringstream returnStream;
    returnStream << "Cat: " << name << ", " << age;
    return returnStream.str();
}

Dog::Dog(string name, int age)
    : Animal(name, age) {}

string Dog::toString() {
    stringstream returnStream;
    returnStream << "Dog: " << name << ", " << age;
    return returnStream.str();
}

void testAnimal() {
    vector<unique_ptr<Animal>> animals;
    animals.emplace_back(new Cat("Pus", 1));
    animals.emplace_back(new Dog("Dyr", 8));
    animals.emplace_back(new Cat("Katt", 9));
    animals.emplace_back(new Cat("Kenguru", 54));
    animals.emplace_back(new Dog("Bikkje", 5));

    for (unique_ptr<Animal>& animal : animals) {
        cout << animal->toString() << endl;
    }
    animals.clear();
}