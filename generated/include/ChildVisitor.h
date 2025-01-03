#ifndef CHILDVISITOR_H
#define CHILDVISITOR_H

#include "Visitor.h"

/**
 * @brief Represents a child visitor to the amusement park.
 *
 * This class extends the `Visitor` class and models a visitor who is a child.
 * It provides specific behavior for child visitors when visiting attractions.
 */
class ChildVisitor : public Visitor {
public:
    /**
     * @brief Constructor for the ChildVisitor class.
     *
     * Initializes a child visitor with the given parameters.
     *
     * @param name The name of the child visitor.
     * @param age The age of the child visitor.
     * @param height The height of the child visitor in cm.
     * @param ticket The ticket of the child visitor.
     */
    ChildVisitor(std::string name, int age, int height, std::shared_ptr<Ticket> ticket);

    /**
     * @brief Simulates the child visitor visiting an attraction.
     *
     * This function defines the behavior of a child visiting an attraction.
     */

    void displayVisitor() const override {
        std::cout << "Child - ";
        Visitor::displayVisitor(); // Call the base class displayVisitor
    }

    void visitAttraction(const std::shared_ptr<Attraction> &attraction) const override;

    /**
     * @brief Gets the type of the visitor.
     *
     * @return A string representing the type of the visitor ("Child").
     */
    std::string getType() const override;
};

#endif // CHILDVISITOR_H
