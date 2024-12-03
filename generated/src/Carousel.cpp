#include "Carousel.h"
#include <iostream>

/**
 * @brief Constructor for the Carousel class.
 *
 * Initializes the carousel with a name, duration, minimum height requirement, maximum capacity of riders,
 * and maximum number of visitors. The constructor calls the base class constructor to initialize common attributes.
 *
 * @param name Name of the carousel.
 * @param duration Duration of the carousel ride in minutes.
 * @param minHeight Minimum height required to ride the carousel in centimeters.
 * @param maxCapacity Maximum number of riders that can ride the carousel simultaneously.
 * @param maxVisitors Maximum number of visitors allowed in the carousel at a time.
 */
Carousel::Carousel(const std::string& name, double duration, int minHeight, int maxCapacity, int maxVisitors)
    : Attraction(name, duration, minHeight, maxVisitors), maxCapacity(maxCapacity) {}

/**
 * @brief Simulates the experience of riding the carousel.
 *
 * Prints a message indicating the number of riders allowed on the carousel at the same time.
 */
void Carousel::simulateExperience() const {
    std::cout << "Take a magical ride on the " << getName() << " with up to " << maxCapacity << " riders at the same time!\n";
}

/**
 * @brief Clones the carousel attraction.
 *
 * Creates a new instance of the Carousel class by copying the current instance.
 *
 * @return A unique pointer to the cloned Carousel object.
 */
std::unique_ptr<Attraction> Carousel::clone() const {
    return std::make_unique<Carousel>(*this);
}

/**
 * @brief Simulates the carousel spinning.
 *
 * Prints a message indicating the carousel is spinning and children are enjoying the ride.
 */
void Carousel::spinAround() const {
    std::cout << "The " << getName() << " is spinning and kids are having fun!\n";
}
