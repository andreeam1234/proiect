#include "RollerCoaster.h"
#include <iostream>

/**
 * @brief Constructor for the RollerCoaster class.
 *
 * Initializes the roller coaster attraction with its name, duration, minimum height, speed, and maximum visitors.
 *
 * @param name The name of the roller coaster.
 * @param duration The duration of the ride.
 * @param minHeight The minimum height required to ride.
 * @param speed The top speed of the roller coaster.
 * @param maxVisitors The maximum number of visitors allowed for the attraction.
 */
RollerCoaster::RollerCoaster(const std::string& name, double duration, int minHeight, int speed, int maxVisitors)
    : Attraction(name, duration, minHeight, maxVisitors), speed(speed) {}

/**
 * @brief Simulates the experience of riding the roller coaster.
 *
 * Prints the experience details including the roller coaster's top speed.
 */
void RollerCoaster::simulateExperience() const {
    std::cout << "Experience the thrill of " << getName() << " at a top speed of " << speed << " km/h!\n" << std::endl;
}

/**
 * @brief Clones the roller coaster attraction.
 *
 * @return A unique pointer to a new instance of the RollerCoaster with the same properties.
 */
std::unique_ptr<Attraction> RollerCoaster::clone() const {
    return std::make_unique<RollerCoaster>(*this);
}

/**
 * @brief Simulates the scream test of the roller coaster.
 *
 * Prints the message indicating that people are screaming on the roller coaster.
 */
void RollerCoaster::screamTest() const {
    std::cout << "People are screaming on the Roller Coaster: " << getName() << "!\n";
}
