#include "FerrisWheel.h"
#include <iostream>

FerrisWheel::FerrisWheel(const std::string& name, double duration, int minHeight, int numberCabins, int maxVisitors)
    : Attraction(name, duration, minHeight, maxVisitors), numberCabins(numberCabins) {}


void FerrisWheel::simulateExperience() const {
    std::cout << "Enjoy the scenic views from " << getName() << " with " << numberCabins << " cabins.\n";
}

std::unique_ptr<Attraction> FerrisWheel::clone() const {
    return std::make_unique<FerrisWheel>(*this);
}

void FerrisWheel::enjoyView() const {
    std::cout << "Visitors are enjoying the view on the Ferris Wheel: " << getName() << "!\n";
}
