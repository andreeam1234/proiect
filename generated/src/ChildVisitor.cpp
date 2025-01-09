#include "ChildVisitor.h"
#include <iostream>

ChildVisitor::ChildVisitor(std::string name, int age, int height, std::shared_ptr<Ticket> ticket)
    : Visitor(name, age, height, ticket) {
}

void ChildVisitor::visitAttraction(const std::shared_ptr<Attraction> &attraction) const {
    std::cout << "Visiting attraction: " << attraction->getName() << std::endl;
}

std::string ChildVisitor::getType() const {
    return "Child";
}
