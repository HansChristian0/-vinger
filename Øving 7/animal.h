#pragma once
#include "std_lib_facilities.h"

class Animal {
protected:
    string name;
    int age;

public:
    Animal(string name, int age);
    virtual ~Animal();

    virtual string toString() = 0;
};

class Cat : public Animal {
public:
    Cat(string name, int age);
    string toString();
};

class Dog : public Animal {
public:
    Dog(string name, int age);
    string toString();
};

void testAnimal();