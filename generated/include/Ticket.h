#ifndef TICKET_H
#define TICKET_H

#include <string>

/**
 * @brief Represents a ticket for an attraction or event.
 *
 * This class manages ticket information including type, price, and validity status.
 */
class Ticket {
private:
    std::string type; /**< The type of the ticket (e.g., standard, VIP). */
    double price; /**< The price of the ticket. */
    bool isValid; /**< A flag indicating if the ticket is valid. */

public:
    /**
     * @brief Constructs a new Ticket object.
     *
     * Initializes the ticket with a given price, type, and validity status.
     *
     * @param price The price of the ticket.
     * @param type The type of the ticket.
     * @param isValid The validity status of the ticket.
     */
    Ticket(double price, const std::string &type, bool isValid);

    /**
     * @brief Retrieves the type of the ticket.
     *
     * @return The type of the ticket.
     */
    [[nodiscard]] std::string getType() const;

    /**
     * @brief Retrieves the price of the ticket.
     *
     * @return The price of the ticket.
     */
    [[nodiscard]] double getPrice() const;

    /**
     * @brief Checks if the ticket is valid.
     *
     * @return A boolean indicating if the ticket is valid.
     */
    [[nodiscard]] bool isValidTicket() const;

    /**
     * @brief Validates the ticket.
     *
     * This function throws an exception if the ticket is invalid.
     *
     * @throws std::invalid_argument if the ticket is invalid.
     */
    void validate() const;
};

#endif // TICKET_H
