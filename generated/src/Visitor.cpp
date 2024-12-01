#include "Visitor.h"
#include <iostream>
#include "VisitorTooShortException.h"

Visitor::Visitor(std::string name, int age, int height, std::shared_ptr<Ticket> ticket)
    : name(std::move(name)), age(age), height(height), ticket(std::move(ticket)) {}

void Visitor::printTicketInfo() const {
    std::cout << name << "'s Ticket:\n";
    std::cout << "Type: " << ticket->getType() << "\n";
    std::cout << "Price: $" << ticket->getPrice() << "\n";
}

void Visitor::visitAttraction(const std::shared_ptr<Attraction>& attraction) const {
    if (height < attraction->getMinHeight()) {
        throw VisitorTooShortException();
    }
    std::cout << name << " is visiting " << attraction->getName() << "!\n";
    attraction->simulateExperience();
}

std::string Visitor::getName() const {
    return name;
}

int Visitor::getAge() const {
    return age;
}

int Visitor::getHeight() const {
    return height;
}

std::shared_ptr<Ticket> Visitor::getTicket() const {
    return ticket;
}
