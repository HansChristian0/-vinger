#include "car.h"

Car::Car(int freeSeats) {
    this->freeSeats= freeSeats;
}

bool Car::hasFreeSeats() const {
    if (this->freeSeats > 0) {
        return true;
    }
    return false;
}

void Car::reserveFreeSeat(){
    this->freeSeats -= 1;
}