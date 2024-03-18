#include "car.h"
#include "iostream"
int main() {
    Car ford(3);
    if (ford.hasFreeSeats()){
        std::cout << "Ledig" << std::endl;
    } else {
        std::cout << "Opptatt" << std::endl;
    }
    ford.reserveFreeSeat();
    ford.reserveFreeSeat();
    if (ford.hasFreeSeats()){
        std::cout << "Ledig" << std::endl;
    } else {
        std::cout << "Opptatt" << std::endl;
    }
    return 0;
}