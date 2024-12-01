#include "FerrisWheel.h"
#include <iostream>

FerrisWheel::FerrisWheel(const std::string& name, double duration, int minHeight, int numberCabins, int maxVisitors)
    :Attraction(name, duration, minHeight), numberCabins(numberCabins) {}

void FerrisWheel::simulateExperience() const {
    std::cout << "Enjoy the scenic views from " << getName() << "with" << numberCabins << "cabins"<< std::endl;
}
FerrisWheel *FerrisWheel::clone() const {
    return new FerrisWheel(*this);
}