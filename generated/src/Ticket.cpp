#include "Ticket.h"
#include "TicketInvalidException.h"
#include <iostream>

Ticket::Ticket(double price, const std::string &type, bool isValid)
    : type(type), price(price), isValid(isValid) {
}

std::string Ticket::getType() const {
    return type;
}

double Ticket::getPrice() const {
    return price;
}

bool Ticket::isValidTicket() const {
    return isValid;
}

void Ticket::validate() const {
    if (!isValid) {
        throw TicketInvalidException();
    }
}
