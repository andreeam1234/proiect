#include "RollerCoaster.h"
#include <iostream>

RollerCoaster::RollerCoaster(const std::string& name, double duration, int minHeight, int speed, int maxVisitors)
    : Attraction(name, duration, minHeight, maxVisitors), speed(speed) {};

void RollerCoaster::simulateExperience() const {
    std::cout << "Experience the thrill of" << getName() << "at a top speed of" << speed<< "km/h!\n" << std::endl;
}


