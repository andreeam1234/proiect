/**
 * @file main.cpp
 * @brief Main entry point for the amusement park simulation.
 *
 * This file sets up an amusement park, adds attractions, visitors, and calculates profit.
 * It also handles exceptions such as invalid tickets, visitor height restrictions, and max visitors exceeded.
 */

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

/**
 * @brief Initializes the park and its attractions, and simulates visitor experiences.
 *
 * Creates the park, adds various attractions to it, and generates visitors with tickets.
 * Visitors then visit the park and attractions, and the program calculates the park's profit.
 */
int main() {
    /**
     * @brief Create the park and add attractions.
     */
    Park park("FunLand");

    /**
     * @brief Create the attractions with specific parameters.
     */
    auto ferrisWheel = std::make_shared<FerrisWheel>("Big Wheel", 10.0, 120, 10, 50);
    auto carousel = std::make_shared<Carousel>("Magic Carousel", 5.0, 100, 20, 70);
    auto rollerCoaster = std::make_shared<RollerCoaster>("Speed Racer", 2.0, 140, 80, 40);

    /**
     * @brief Add the attractions to the park.
     */
    park.addAttraction(ferrisWheel);
    park.addAttraction(carousel);
    park.addAttraction(rollerCoaster);

    /**
     * @brief Create tickets for visitors.
     */
    auto ticket1 = std::make_shared<Ticket>(50.0, "Adult", true);
    auto ticket2 = std::make_shared<Ticket>(30.0, "Child", false);

    /**
     * @brief Create visitors with corresponding tickets.
     */
    auto visitor1 = std::make_shared<Visitor>("John", 25, 180, ticket1);
    auto visitor2 = std::make_shared<Visitor>("Alice", 4, 90, ticket2);

    /**
     * @brief Visitors visit the park.
     */
    visitor1->visitPark();
    visitor2->visitPark();

    /**
     * @brief Add visitors to the park.
     */
    park.addVisitor(visitor1);
    park.addVisitor(visitor2);

    try {
        /**
         * @brief Display attractions and visitors.
         */
        park.showAttractions();
        park.showVisitors();

        /**
         * @brief Simulate visitors visiting the attractions.
         */
        park.visitAttractions();

        /**
         * @brief Calculate and display the total profit of the park.
         */
        std::cout << "Total profit: " << park.calcTotalProfit() << "$" << std::endl;
    }
    catch (const MaxVisitorsExceededException& e) {
        /**
         * @brief Handle exception when maximum visitors exceed the limit.
         */
        std::cout << e.what() << std::endl;
    }
    catch (const TicketInvalidException& e) {
        /**
         * @brief Handle exception when a visitor has an invalid ticket.
         */
        std::cout << e.what() << std::endl;
    }
    catch (const VisitorTooShortException& e) {
        /**
         * @brief Handle exception when a visitor is too short for an attraction.
         */
        std::cout << e.what() << std::endl;
    }

    return 0;
}
