#include "RollerCoaster.h"
#include <iostream>

RollerCoaster::RollerCoaster(const std::string& name, double duration, int minHeight, int speed, int maxVisitors)
    : Attraction(name, duration, minHeight, maxVisitors), speed(speed) {}

void RollerCoaster::simulateExperience() const {
    std::cout << "Experience the thrill of " << getName() << " at a top speed of " << speed << " km/h!\n" << std::endl;
}

std::unique_ptr<Attraction> RollerCoaster::clone() const {
    return std::make_unique<RollerCoaster>(*this);
}

void RollerCoaster::screamTest() const {
    std::cout << "People are screaming on the Roller Coaster: " << getName() << "!\n";
}
