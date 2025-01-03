#include "ChildVisitor.h"
#include <iostream>

ChildVisitor::ChildVisitor(std::string name, int age, int height, std::shared_ptr<Ticket> ticket)
    : Visitor(name, age, height, ticket) {
}

void ChildVisitor::visitAttraction(const std::shared_ptr<Attraction> &attraction) const {
    // Logic specific to children visiting attractions
    std::cout << name << " (Child) is enjoying a child-friendly attraction!" << std::endl;
}

std::string ChildVisitor::getType() const {
    return "Child";
}
