#include "Park.h"
#include <iostream>
#include "VisitorTooShortException.h"
#include "TicketInvalidException.h"
#include "MaxVisitorsExceededException.h"
#include "Carousel.h"
#include "RollerCoaster.h"
#include "FerrisWheel.h"

int Park::totalVisitors = 0;

Park::Park(const std::string& name) : name(name) {}

void Park::addAttraction(const std::shared_ptr<Attraction>& attraction) {
    attractions.push_back(attraction);
}

const std::vector<std::shared_ptr<Attraction>>& Park::getAttractions() const {
    return attractions;
}

void Park::addVisitor(const std::shared_ptr<Visitor>& visitor) {
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
    for (const auto& attraction : attractions) {
        if (auto rollerCoaster = dynamic_cast<RollerCoaster*>(attraction.get())) {
            rollerCoaster->screamTest();
        }
        else if (auto carousel = dynamic_cast<Carousel*>(attraction.get())) {
            carousel->spinAround();
        }

        else if (auto ferrisWheel = dynamic_cast<FerrisWheel*>(attraction.get())) {
            ferrisWheel->enjoyView();
        }
        else {
            attraction->describe();
        }
    }
    for (const auto& visitor : visitors) {
        for (const auto& attraction : attractions) {
            try {
                visitor->visitAttraction(attraction);
            } catch (const VisitorTooShortException& e) {
                std::cout << visitor->getName() << " is too short to visit " << attraction->getName() << "\n";
                std::cout << e.what() << std::endl;
            } catch (const MaxVisitorsExceededException& e) {
                std::cout << "Max visitors exceeded for " << attraction->getName() << "\n";
                std::cout << e.what() << std::endl;
            }
        }
    }
}


double Park::calcTotalProfit() const {
    double totalProfit = 0;

    for (const auto& visitor : visitors) {
        if (!visitor->getTicket() || visitor->getTicket()->getPrice() <= 0) {
            throw TicketInvalidException();
        }

        totalProfit += visitor->getTicket()->getPrice();
    }

    return totalProfit;
}
double Park::averageTimeSpent() const {
    double totalTime = 0;
    int numberVisitors = 0;
    for (const auto& visitor : visitors) {
        totalTime += visitor->getTimeSpent();
        numberVisitors++;
    }
    return (numberVisitors > 0) ? totalTime / numberVisitors : 0.0;
}

void Park::incrementTotalVisitors() {
    totalVisitors++;
}

int Park::getTotalVisitors() {
    return totalVisitors;
}
