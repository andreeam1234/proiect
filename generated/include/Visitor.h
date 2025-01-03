#ifndef VISITOR_H
#define VISITOR_H

#include <string>
#include <memory>
#include "Ticket.h"
#include "Attraction.h"
#include "Observer.h"
#include <vector>
#include <algorithm>

/**
 * @brief Represents a visitor to the amusement park.
 *
 * This class models a visitor with information such as their name, age, height, and ticket.
 * The visitor can visit attractions, track the time spent.
 */
class Visitor : public Observer {
protected:
    std::string name; /**< The name of the visitor. */
    int age; /**< The age of the visitor. */
    int height; /**< The height of the visitor in cm. */
    std::shared_ptr<Ticket> ticket; /**< The ticket of the visitor. */
    mutable double timeSpent; /**< The time spent by the visitor on attractions. */

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

    void update(const std::string &eventMessage) override;

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
    virtual void visitAttraction(const std::shared_ptr<Attraction> &attraction) const;

    /**
     * @brief Simulates the visitor visiting the park.
     *
     * This function simulates a visitor entering and enjoying the park.
     */
    static void visitPark();

    /**
     * @brief Virtual function to return the type of visitor ("Child" or "Adult").
     *
     * @return A string representing the visitor type.
     */
    virtual std::string getType() const = 0;

    template<typename T>
    static void sortVisitors(std::vector<std::shared_ptr<T> > &visitors,
                             bool (*compare)(const std::shared_ptr<T> &, const std::shared_ptr<T> &)) {
        std::sort(visitors.begin(), visitors.end(), compare);
    }

 /**
      * @brief Display the visitor's information.
      */
 virtual void displayVisitor() const {
     std::cout << "Name: " << name << ", Age: " << age << ", Height: " << height << std::endl;
    }

    /**
     * @brief Comparison function for sorting by age.
     */
    template<typename T>
    static bool compareByAge(const std::shared_ptr<T> &visitor1, const std::shared_ptr<T> &visitor2) {
        return visitor1->getAge() < visitor2->getAge();
    }

    /**
     * @brief Comparison function for sorting by height.
     */
    template<typename T>
    static bool compareByHeight(const std::shared_ptr<T> &visitor1, const std::shared_ptr<T> &visitor2) {
        return visitor1->getHeight() < visitor2->getHeight();
    }
};

#endif // VISITOR_H
