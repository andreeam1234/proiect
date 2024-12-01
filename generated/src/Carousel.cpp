#include "Carousel.h"
#include <iostream>

Carousel::Carousel(const std::string& name, double duration, int minHeight, int maxCapacity, int maxVisitors)
    : Attraction(name, duration, minHeight, maxVisitors), maxCapacity(maxCapacity) {}

void Carousel::simulateExperience() const {
    std::cout << "Take a magical ride on the " << getName() << "with up to " << maxCapacity << "riders at the same time!\n" ;
}
Carousel *Carousel::clone() const {
    return new Carousel(*this);
}