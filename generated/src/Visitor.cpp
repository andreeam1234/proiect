#include "Visitor.h"
#include <iostream>

Visitor::Visitor(std::string name, int age, std::shared_ptr<Ticket> ticket)
    : name(std::move(name)), age(age), ticket(std::move(ticket)) {}

void Visitor::printTicketInfo() const {
    std::cout << name << "'s Ticket:\n";
    std::cout << "Type: " << ticket->getType() << "\n";
    std::cout << "Price: $" << ticket->getPrice() << "\n";
}

void Visitor::visitAttraction(const std::shared_ptr<Attraction>& attraction) const {
    if (age >= attraction->getMinHeight()) {
        attraction->simulateExperience();
    } else {
        std::cout << name << " is not tall enough to visit " << attraction->getName() << "!\n";
    }
}

std::string Visitor::getName() const {
    return name;
}

int Visitor::getAge() const {
    return age;
}

std::shared_ptr<Ticket> Visitor::getTicket() const {
    return ticket;
}
