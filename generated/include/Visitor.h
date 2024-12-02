#ifndef VISITOR_H
#define VISITOR_H

#include <string>
#include <memory>
#include "Ticket.h"
#include "Attraction.h"

/**
 * @brief Represents a visitor to the amusement park.
 *
 * This class models a visitor with information such as their name, age, height, and ticket.
 * The visitor can visit attractions, track the time spent, and print ticket information.
 */
class Visitor {
    std::string name; /**< The name of the visitor. */
    int age; /**< The age of the visitor. */
    int height; /**< The height of the visitor in cm. */
    std::shared_ptr<Ticket> ticket; /**< The ticket of the visitor. */
    double timeSpent; /**< The time spent by the visitor on attractions. */

public:
    /**
     * @brief Constructs a new Visitor object.
     *
     * Initializes the visitor with the given parameters.
     *
     * @param name The name of the visitor.
     * @param age The age of the visitor.
     * @param height The height of the visitor in cm.
     * @param ticket The ticket of the visitor.
     */
    Visitor(std::string name, int age, int height, std::shared_ptr<Ticket> ticket);

    /**
     * @brief Gets the name of the visitor.
     *
     * @return The name of the visitor.
     */
    [[nodiscard]] std::string getName() const;

    /**
     * @brief Gets the age of the visitor.
     *
     * @return The age of the visitor.
     */
    [[nodiscard]] int getAge() const;

    /**
     * @brief Gets the height of the visitor.
     *
     * @return The height of the visitor in cm.
     */
    [[nodiscard]] int getHeight() const;

    /**
     * @brief Gets the ticket of the visitor.
     *
     * @return A shared pointer to the visitor's ticket.
     */
    [[nodiscard]] std::shared_ptr<Ticket> getTicket() const;

    /**
     * @brief Gets the time spent by the visitor on attractions.
     *
     * @return The time spent by the visitor on attractions in hours.
     */
    [[nodiscard]] double getTimeSpent() const;

    /**
     * @brief Prints the ticket information of the visitor.
     *
     * This function displays the type, price, and validity of the ticket.
     */
    void printTicketInfo() const;

    /**
     * @brief Simulates the visitor visiting an attraction.
     *
     * The visitor spends time at the given attraction and their timeSpent is updated.
     *
     * @param attraction A shared pointer to the attraction the visitor is visiting.
     */
    void visitAttraction(const std::shared_ptr<Attraction>& attraction) const;

    /**
     * @brief Simulates the visitor visiting the park.
     *
     * This function simulates a visitor entering and enjoying the park.
     */
    static void visitPark();
};

#endif // VISITOR_H
