#ifndef TICKETINVALIDEXCEPTION_H
#define TICKETINVALIDEXCEPTION_H

#include <exception>

/**
 * @brief Exception thrown when a ticket is invalid.
 *
 * This exception is thrown when an operation is attempted with an invalid ticket.
 */
class TicketInvalidException : public std::exception {
public:
    /**
     * @brief Returns the error message for the exception.
     *
     * @return A C-string with the error message indicating the ticket is invalid.
     */
    [[nodiscard]] const char* what() const noexcept override {
        return "The ticket is invalid!";
    }
};

#endif // TICKETINVALIDEXCEPTION_H
