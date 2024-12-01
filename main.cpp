#include <memory>
#include "Park.h"
#include "FerrisWheel.h"
#include "Carousel.h"
#include "RollerCoaster.h"
#include "Visitor.h"
#include "Ticket.h"
#include <iostream>

int main() {
    Park park("Adventure Park");

    auto ferrisWheel = std::make_shared<FerrisWheel>("Big Wheel", 10.0, 120, 10);
    auto carousel = std::make_shared<Carousel>("Magic Carousel", 5.0, 100, 20);
    auto rollerCoaster = std::make_shared<RollerCoaster>("Speed Racer", 2.0, 140, 80);

    park.addAttraction(ferrisWheel);
    park.addAttraction(carousel);
    park.addAttraction(rollerCoaster);

    auto ticket1 = std::make_shared<Ticket>(50.0, "Adult");
    auto ticket2 = std::make_shared<Ticket>(30.0, "Child");

    auto visitor1 = std::make_shared<Visitor>("John", 25, ticket1);
    auto visitor2 = std::make_shared<Visitor>("Alice", 10, ticket2);

    park.addVisitor(visitor1);
    park.addVisitor(visitor2);

    park.showAttractions();
    park.showVisitors();

    park.visitAttractions();

    return 0;
}
