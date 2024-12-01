#include "Park.h"
#include <iostream>

Park::Park(const std::string& name) : name(name) {}  // referință constantă

void Park::addAttraction(const std::shared_ptr<Attraction>& attraction) {  // folosește referință constantă
    attractions.push_back(attraction);
}

void Park::addVisitor(const std::shared_ptr<Visitor>& visitor) {  // folosește referință constantă
    visitors.push_back(visitor);
}

void Park::showAttractions() const {
    std::cout << "Attractions in " << name << ":\n";
    for (const auto& attraction : attractions) {
        std::cout << *attraction << std::endl;
    }
}

void Park::showVisitors() const {
    std::cout << "Visitors in " << name << ":\n";
    for (const auto& visitor : visitors) {
        std::cout << visitor->getName() << " (Age: " << visitor->getAge() << ")\n";
    }
}

void Park::visitAttractions() const {
    for (const auto& visitor : visitors) {
        for (const auto& attraction : attractions) {
            visitor->visitAttraction(attraction);
        }
    }
}

double Park::calcTotalProfit() const {
    double totalProfit = 0;

    for(const auto& visitor : visitors) {
        for(const auto& attraction : attractions) {
            totalProfit += visitor->getTicket()->getPrice();
        }
    }
    return totalProfit;
}

double Park::averageTimeSpent() const {
    double totalTime = 0;
    int numberVisitors = 0;

    for(const auto& visitor : visitors) {
        for(const auto& attraction : attractions) {
            totalTime += visitor->getTicket()->getPrice();
        }
        numberVisitors++;
    }
    return (numberVisitors > 0) ? totalTime / numberVisitors : 0.0;
}
