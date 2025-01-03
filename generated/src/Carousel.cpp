#include "Carousel.h"
#include <iostream>


Carousel::Carousel(const std::string &name, double duration, int minHeight, int maxCapacity, int maxVisitors)
    : Attraction(name, duration, minHeight, maxVisitors), maxCapacity(maxCapacity) {
}

void Carousel::simulateExperience() const {
    std::cout << "Take a magical ride on the " << getName() << " with up to " << maxCapacity <<
            " riders at the same time!\n";
}

std::unique_ptr<Attraction> Carousel::clone() const {
    return std::make_unique<Carousel>(*this);
}

void Carousel::spinAround() const {
    std::cout << "The " << getName() << " is spinning and kids are having fun!\n";
}
