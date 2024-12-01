#include "RollerCoaster.h"
#include <iostream>

RollerCoaster::RollerCoaster(const std::string& name, double duration, int minHeight, int speed)
    : Attraction(name, duration, minHeight), speed(speed) {};

void RollerCoaster::simulateExperience() const {
    std::cout << "Experience the thrill of" << getName() << "at a top speed of" << speed<< "km/h!\n" << std::endl;
}

RollerCoaster* RollerCoaster::clone() const {
    return new RollerCoaster(*this);
}

