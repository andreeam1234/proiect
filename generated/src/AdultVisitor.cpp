#include "AdultVisitor.h"
#include "VisitorTooShortException.h"
#include <iostream>

AdultVisitor::AdultVisitor(std::string name, int age, int height, std::shared_ptr<Ticket> ticket)
    : Visitor(std::move(name), age, height, std::move(ticket)) {
}

void AdultVisitor::visitAttraction(const std::shared_ptr<Attraction> &attraction) const {
    if (getHeight() < attraction->getMinHeight()) {
        throw VisitorTooShortException();
    }
    timeSpent += attraction->getDuration();
    std::cout << getName() << " is visiting " << attraction->getName() << "!\n";
    attraction->simulateExperience();
}

std::string AdultVisitor::getType() const {
    return "Adult";
}
