#include "Visitor.h"
#include "Park.h"
#include <iostream>
#include "VisitorTooShortException.h"

/**
 * @brief Constructor for the Visitor class.
 *
 * Initializes a visitor with the provided name, age, height, and ticket.
 *
 * @param name The name of the visitor.
 * @param age The age of the visitor.
 * @param height The height of the visitor.
 * @param ticket A shared pointer to the visitor's ticket.
 */
Visitor::Visitor(std::string name, int age, int height, std::shared_ptr<Ticket> ticket)
    : name(std::move(name)), age(age), height(height), ticket(std::move(ticket)), timeSpent(0) {}

/**
 * @brief Prints the ticket information for the visitor.
 *
 * Displays the type and price of the visitor's ticket.
 */
void Visitor::printTicketInfo() const {
    std::cout << name << "'s Ticket:\n";
    std::cout << "Type: " << ticket->getType() << "\n";
    std::cout << "Price: $" << ticket->getPrice() << "\n";
}

/**
 * @brief Visitor visits an attraction.
 *
 * Simulates the experience at the attraction.
 *
 * @param attraction The attraction the visitor is
 *
 * @throws VisitorTooShortException If the visitor is too short for the attraction.
 */
void Visitor::visitAttraction(const std::shared_ptr<Attraction>& attraction) const {
    if (height < attraction->getMinHeight()) {
        throw VisitorTooShortException();
    }
    timeSpent += attraction->getDuration();
    std::cout << name << " is visiting " << attraction->getName() << "!\n";
    attraction->simulateExperience();
}

/**
 * @brief Gets the name of the visitor.
 *
 * @return The name of the visitor.
 */
std::string Visitor::getName() const {
    return name;
}

/**
 * @brief Gets the age of the visitor.
 *
 * @return The age of the visitor.
 */
int Visitor::getAge() const {
    return age;
}

/**
 * @brief Gets the height of the visitor.
 *
 * @return The height of the visitor in centimeters.
 */
int Visitor::getHeight() const {
    return height;
}

/**
 * @brief Gets the time spent by the visitor in the park.
 *
 * @return The time spent by the visitor in the park.
 */
double Visitor::getTimeSpent() const {
    return timeSpent;
}

/**
 * @brief Increments the total number of visitors in the park.
 *
 * This method is used to track the number of visitors in the park.
 */
void Visitor::visitPark() {
    static bool visited = false;
    if(!visited) {
        Park::incrementTotalVisitors();
        visited = true;
    }
}

/**
 * @brief Gets the ticket associated with the visitor.
 *
 * @return A shared pointer to the visitor's ticket.
 */
std::shared_ptr<Ticket> Visitor::getTicket() const {
    return ticket;
}
