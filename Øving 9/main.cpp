#include "car.h"
#include "iostream"
#include "person.h"

int main() {
    Person Per("Per", "gmail.com");

    std::cout << &Per;
    return 0;
}