#include <memory>
#include "Park.h"
#include "FerrisWheel.h"
#include "Carousel.h"
#include "RollerCoaster.h"
#include "Visitor.h"
#include "Ticket.h"
#include "MaxVisitorsExceededException.h"
#include "TicketInvalidException.h"
#include "VisitorTooShortException.h"
#include <iostream>

int main() {
    Park park("Adventure Park");

    auto ferrisWheel = std::make_shared<FerrisWheel>("Big Wheel", 10.0, 120, 10, 50);
    auto carousel = std::make_shared<Carousel>("Magic Carousel", 5.0, 100, 20, 70);
    auto rollerCoaster = std::make_shared<RollerCoaster>("Speed Racer", 2.0, 140, 80, 40);

    park.addAttraction(ferrisWheel);
    park.addAttraction(carousel);
    park.addAttraction(rollerCoaster);

    auto ticket1 = std::make_shared<Ticket>(50.0, "Adult", true);
    auto ticket2 = std::make_shared<Ticket>(30.0, "Child", false);

    auto visitor1 = std::make_shared<Visitor>("John", 25, 180, ticket1);
    auto visitor2 = std::make_shared<Visitor>("Alice", 10, 90, ticket2); // Alice este prea mică pentru unele atracții

    park.addVisitor(visitor1);
    park.addVisitor(visitor2);

    try {
        park.showAttractions();
        park.showVisitors();

        park.visitAttractions();

        std::cout << "Total profit: " << park.calcTotalProfit() << "$" << std::endl;
        std::cout << "Average time spent: " << park.averageTimeSpent() << " minutes" << std::endl;
    }
    catch (const MaxVisitorsExceededException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (const TicketInvalidException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (const VisitorTooShortException& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
