#include "Ticket.h"

Ticket::Ticket(double price, std::string type) : price(price), type(std::move(type)) {}

double Ticket::getPrice() const {
    return price;
}

std::string Ticket::getType() const {
    return type;
}