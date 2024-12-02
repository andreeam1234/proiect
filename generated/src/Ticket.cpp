#include "Ticket.h"
#include "TicketInvalidException.h"
#include <iostream>

/**
 * @brief Constructor for the Ticket class.
 *
 * Initializes a ticket with the specified type, price, and validity status.
 *
 * @param price The price of the ticket.
 * @param type The type of the ticket (e.g., single ride, day pass).
 * @param isValid The validity status of the ticket.
 */
Ticket::Ticket(double price, const std::string& type, bool isValid)
    : type(type), price(price), isValid(isValid) {}

/**
 * @brief Gets the type of the ticket.
 *
 * @return A string representing the type of the ticket.
 */
std::string Ticket::getType() const {
    return type;
}

/**
 * @brief Gets the price of the ticket.
 *
 * @return The price of the ticket.
 */
double Ticket::getPrice() const {
    return price;
}

/**
 * @brief Checks if the ticket is valid.
 *
 * @return true if the ticket is valid, otherwise false.
 */
bool Ticket::isValidTicket() const {
    return isValid;
}

/**
 * @brief Validates the ticket.
 *
 * Throws a TicketInvalidException if the ticket is not valid.
 *
 * @throws TicketInvalidException If the ticket is invalid.
 */
void Ticket::validate() const {
    if (!isValid) {
        throw TicketInvalidException();
    }
}

/**
 * @brief Prints information about the ticket.
 *
 * Displays the type, price, and validity status of the ticket.
 */
void Ticket::printInfo() const {
    std::cout << "Ticket Type: " << type << ", Price: " << price << ", Valid: " << (isValid ? "Yes" : "No") << std::endl;
}
