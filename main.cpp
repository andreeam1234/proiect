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
#include "Ticket_factory.h"
#include "AdultVisitor.h"
#include "ChildVisitor.h"
#include "Visitor_list.h"

/**
 * @brief Initializes the park and its attractions, and simulates visitor experiences.
 *
 * Creates the park, adds attractions to it and generates visitors with tickets.
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

    /**
     * @brief Create ticket factories.
     */

    StandardTicketFactory standardFactory;
    VIPTicketFactory vipFactory;

    /**
     *@brief Create tickets using the factories.
     */
    auto standardTicket = std::shared_ptr<Ticket>(standardFactory.createTicket());
    auto vipTicket = std::shared_ptr<Ticket>(vipFactory.createTicket());

    auto ferrisWheel = std::make_shared<FerrisWheel>("Big Wheel", 10.0, 120, 10, 50);
    auto carousel = std::make_shared<Carousel>("Magic Carousel", 5.0, 100, 20, 70);
    auto rollerCoaster = std::make_shared<RollerCoaster>("Speed Racer", 2.0, 140, 80, 40);

    /**
     * @brief Add attractions to the park and notify visitors.
     */
    park.addAttraction(ferrisWheel);
    park.notifyObservers("New attraction added: Big Wheel!");
    park.addAttraction(carousel);
    park.notifyObservers("New attraction added: Magic Carousel!");
    park.addAttraction(rollerCoaster);
    park.notifyObservers("New attraction added: Speed Racer!");

    /**
     * @brief Create tickets for visitors.
     */
    auto ticket1 = std::make_shared<Ticket>(50.0, "Adult", true);
    auto ticket2 = std::make_shared<Ticket>(30.0, "Child", false);

    /**
     * @brief Create visitors with corresponding tickets.
     */
    auto visitor1 = std::make_shared<AdultVisitor>("John", 25, 180, ticket1);
    auto visitor2 = std::make_shared<ChildVisitor>("Alice", 4, 90, ticket2);

    /**
     * @brief Visitors visit the park.
     */
    VisitorList<Visitor> visitorList;
    visitorList.addVisitor(visitor1);
    visitorList.addVisitor(visitor2);
    Visitor::sortVisitors(visitorList.getVisitors(), Visitor::compareByAge<Visitor>);
    std::cout << "Sorted visitors by age:" << std::endl;
    visitorList.displayVisitors();

    visitor1->visitPark();
    visitor2->visitPark();

    park.addObserver(visitor1);
    park.addObserver(visitor2);

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
         * @brief Notify observers about park activities.
         */
        park.notifyObservers("All visitors are enjoying the attractions!");
        /**
         * @brief Calculate and display the total profit of the park.
         */
        std::cout << "Total profit: " << park.calcTotalProfit() << "$" << std::endl;
        park.incrementTotalVisitors();
        std::cout << "Total visitors: " << park.getTotalVisitors() << std::endl;
        /**
            * @brief Calculate and display the average time spent by visitors.
            */
        double avgTime = park.averageTimeSpent();
        std::cout << "Average time spent by visitors at attractions: " << avgTime << " minutes." << std::endl;
    } catch (const MaxVisitorsExceededException &e) {
        /**
         * @brief Handle exception when maximum visitors exceed the limit.
         */
        std::cout << e.what() << std::endl;
    }
    catch (const TicketInvalidException &e) {
        /**
         * @brief Handle exception when a visitor has an invalid ticket.
         */
        std::cout << e.what() << std::endl;
    }
    catch (const VisitorTooShortException &e) {
        /**
         * @brief Handle exception when a visitor is too short for an attraction.
         */
        std::cout << e.what() << std::endl;
    }

    /**
        * @brief Notify all visitors about park closing.
        */
    park.notifyObservers("The park is closing. Thank you for visiting FunLand!");
    return 0;
}
