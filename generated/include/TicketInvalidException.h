#ifndef TICKETINVALIDEXCEPTION_H
#define TICKETINVALIDEXCEPTION_H

#include <exception>

class TicketInvalidException : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept {
        return "The ticket is invalid!";
    }
};

#endif //TICKETINVALIDEXCEPTION_H
