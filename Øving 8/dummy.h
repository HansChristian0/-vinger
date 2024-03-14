#pragma once
#include <iostream>
#include <utility>

class Dummy {
public:
    int *num;
    Dummy() {
        num = new int{0};
    }
    Dummy(const Dummy& other) {
        this->num = new int{};
        *num = *other.num;
    }
    ~Dummy() {
        delete num;
    }
    Dummy& operator=(const Dummy& other) {
        delete num;
        num = new int{};
        *num = *other.num;
        return *this;
    }
};
void dummyTest();