#include "Attraction.h"
#include "MaxVisitorsExceededException.h"
#include <iostream>

/**
 * @brief Constructor for the Attraction class.
 *
 * Initializes the attraction with a name, duration, minimum height requirement, and maximum number of visitors.
 * The current number of visitors is initialized to zero.
 *
 * @param name Name of the attraction.
 * @param duration Duration of the attraction's operation in minutes.
 * @param minHeight Minimum height required to participate in the attraction in centimeters.
 * @param maxVisitors Maximum number of visitors allowed in the attraction at a time.
 */
Attraction::Attraction(const std::string& name, double duration, int minHeight, int maxVisitors)
    : name(name), duration(duration), minHeight(minHeight), maxVisitors(maxVisitors), currentVisitors(0) {}

/**
 * @brief Simulates the experience of the attraction.
 *
 * If the maximum number of visitors has been reached, throws a MaxVisitorsExceededException.
 * Otherwise, it prints a message indicating the attraction is running.
 */
void Attraction::simulateExperience() const {
    if (currentVisitors >= maxVisitors) {
        throw MaxVisitorsExceededException();
    }
    std::cout << name << " is now running for a duration of " << duration << " minutes.\n";
}

/**
 * @brief Adds a visitor to the attraction.
 *
 * Increments the current visitor count if the maximum number of visitors has not been reached.
 * Throws a MaxVisitorsExceededException if the attraction is full.
 */
void Attraction::addVisitor() {
    if (currentVisitors < maxVisitors) {
        currentVisitors++;
    } else {
        throw MaxVisitorsExceededException();
    }
}

/**
 * @brief Gets the name of the attraction.
 *
 * @return The name of the attraction.
 */
std::string Attraction::getName() const { return name; }

/**
 * @brief Gets the duration of the attraction.
 *
 * @return The duration in minutes.
 */
double Attraction::getDuration() const { return duration; }

/**
 * @brief Gets the minimum height required for the attraction.
 *
 * @return The minimum height in centimeters.
 */
int Attraction::getMinHeight() const { return minHeight; }

/**
 * @brief Gets the maximum number of visitors for the attraction.
 *
 * @return The maximum number of visitors.
 */
int Attraction::getMaxVisitors() const { return maxVisitors; }

/**
 * @brief Gets the current number of visitors in the attraction.
 *
 * @return The current number of visitors.
 */
int Attraction::getCurrentVisitors() const { return currentVisitors; }

/**
 * @brief Prints a description of the attraction.
 *
 * Outputs the name and duration of the attraction.
 */
void Attraction::describe() const {
    std::cout << "Attraction: " << name << ", Duration: " << duration << "min\n";
}

/**
 * @brief Outputs the details of the attraction to an output stream.
 *
 * @param os Output stream to which the attraction details will be written.
 * @param attraction The attraction to be output.
 * @return The output stream with the attraction's details.
 */
std::ostream& operator<<(std::ostream& os, const Attraction& attraction) {
    os << "Attraction Name: " << attraction.name << "\n"
       << "Duration: " << attraction.duration << " minutes\n"
       << "Minimum Height: " << attraction.minHeight << " cm\n"
       << "Max Visitors: " << attraction.maxVisitors << "\n"
       << "Current Visitors: " << attraction.currentVisitors << "\n";
    return os;
}
