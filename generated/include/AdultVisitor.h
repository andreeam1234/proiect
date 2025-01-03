#ifndef ADULTVISITOR_H
#define ADULTVISITOR_H

#include "Visitor.h"

/**
 * @brief Represents an adult visitor to the amusement park.
 *
 * This class extends the `Visitor` class and models a visitor who is an adult.
 * It provides specific behavior for adult visitors when visiting attractions.
 */
class AdultVisitor : public Visitor {
public:
    /**
     * @brief Constructor for the AdultVisitor class.
     *
     * Initializes an adult visitor with the given parameters.
     *
     * @param name The name of the adult visitor.
     * @param age The age of the adult visitor.
     * @param height The height of the adult visitor in cm.
     * @param ticket The ticket of the adult visitor.
     */
    AdultVisitor(std::string name, int age, int height, std::shared_ptr<Ticket> ticket);

    /**
     * @brief Simulates the adult visitor visiting an attraction.
     *
     * This function defines the behavior of an adult visiting an attraction.
     */

    void displayVisitor() const override {
        std::cout << "Adult - ";
        Visitor::displayVisitor(); // Call the base class displayVisitor
    }

    void visitAttraction(const std::shared_ptr<Attraction> &attraction) const override;

    /**
     * @brief Gets the type of the visitor.
     *
     * @return A string representing the type of the visitor ("Adult").
     */
    std::string getType() const override;
};

#endif // ADULTVISITOR_H
