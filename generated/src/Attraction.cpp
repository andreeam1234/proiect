#include "Attraction.h"
#include "MaxVisitorsExceededException.h"
#include <iostream>

Attraction::Attraction(const std::string& name, double duration, int minHeight, int maxVisitors)
    : name(name), duration(duration), minHeight(minHeight), maxVisitors(maxVisitors), currentVisitors(0) {}

void Attraction::simulateExperience() const {
    if (currentVisitors >= maxVisitors) {
        throw MaxVisitorsExceededException();
    }
    std::cout << name << " is now running for a duration of " << duration << " minutes.\n";

}

void Attraction::addVisitor() {
    if (currentVisitors < maxVisitors) {
        currentVisitors++;
    } else {
        throw MaxVisitorsExceededException();  // Aruncăm excepția dacă se depășește numărul maxim de vizitatori
    }
}

std::string Attraction::getName() const {
    return name;
}

double Attraction::getDuration() const {
    return duration;
}

int Attraction::getMinHeight() const {
    return minHeight;
}

int Attraction::getMaxVisitors() const {
    return maxVisitors;
}

int Attraction::getCurrentVisitors() const {
    return currentVisitors;
}

std::ostream &operator<<(std::ostream &os, const Attraction &attraction) {
    os << "Attraction Name: " << attraction.name << "\n"
       << "Duration: " << attraction.duration << " minutes\n"
       << "Minimum Height: " << attraction.minHeight << " cm\n"
       << "Max Visitors: " << attraction.maxVisitors << "\n"
       << "Current Visitors: " << attraction.currentVisitors << "\n";
    return os;
}
