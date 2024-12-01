#include "Park.h"
#include <iostream>
#include "VisitorTooShortException.h"
#include "TicketInvalidException.h"
#include "MaxVisitorsExceededException.h"

Park::Park(const std::string& name) : name(name) {}

void Park::addAttraction(const std::shared_ptr<Attraction>& attraction) {
    attractions.push_back(attraction);
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
    for (const auto& visitor : visitors) {
        for (const auto& attraction : attractions) {
            try {
                visitor->visitAttraction(attraction);
            } catch (const VisitorTooShortException& e) {
                std::cout << visitor->getName() << " is too short to visit " << attraction->getName() << "\n";
                std::cout << e.what() << std::endl;  // Poți folosi e pentru a afișa un mesaj de eroare detaliat
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
        // Verificăm dacă vizitatorul are un bilet valid
        if (!visitor->getTicket() || visitor->getTicket()->getPrice() <= 0) {
            throw TicketInvalidException();  // Aruncăm excepția dacă biletul este invalid
        }

        totalProfit += visitor->getTicket()->getPrice();  // Adăugăm prețul biletului la profit
    }

    return totalProfit;
}

double Park::averageTimeSpent() const {

    double totalTime = 0;
    int numberVisitors = 0;

    for (const auto& visitor : visitors) {
        totalTime += visitor->getTicket()->getPrice();
        numberVisitors++;
    }
    return (numberVisitors > 0) ? totalTime / numberVisitors : 0.0;
}

