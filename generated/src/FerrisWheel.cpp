#include "FerrisWheel.h"
#include <iostream>

/**
 * @brief Constructor for the FerrisWheel class.
 *
 * Initializes the Ferris Wheel with a name, duration, minimum height requirement, number of cabins,
 * and maximum number of visitors. The constructor calls the base class constructor to initialize common attributes.
 *
 * @param name Name of the Ferris Wheel.
 * @param duration Duration of the ride in minutes.
 * @param minHeight Minimum height required to ride the Ferris Wheel in centimeters.
 * @param numberCabins Number of cabins on the Ferris Wheel.
 * @param maxVisitors Maximum number of visitors allowed on the Ferris Wheel at a time.
 */
FerrisWheel::FerrisWheel(const std::string& name, double duration, int minHeight, int numberCabins, int maxVisitors)
    : Attraction(name, duration, minHeight, maxVisitors), numberCabins(numberCabins) {}

/**
 * @brief Simulates the experience of riding the Ferris Wheel.
 *
 * Prints a message indicating the scenic views that visitors can enjoy from the Ferris Wheel.
 */
void FerrisWheel::simulateExperience() const {
    std::cout << "Enjoy the scenic views from " << getName() << " with " << numberCabins << " cabins.\n";
}

/**
 * @brief Clones the FerrisWheel attraction.
 *
 * Creates a new instance of the FerrisWheel class by copying the current instance.
 *
 * @return A unique pointer to the cloned FerrisWheel object.
 */
std::unique_ptr<Attraction> FerrisWheel::clone() const {
    return std::make_unique<FerrisWheel>(*this);
}

/**
 * @brief Simulates visitors enjoying the view on the Ferris Wheel.
 *
 * Prints a message indicating visitors are enjoying the view on the Ferris Wheel.
 */
void FerrisWheel::enjoyView() const {
    std::cout << "Visitors are enjoying the view on the Ferris Wheel: " << getName() << "!\n";
}
