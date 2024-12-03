#ifndef PARK_H
#define PARK_H

#include <string>
#include <vector>
#include <memory>
#include "Visitor.h"
#include "Attraction.h"

/**
 * @brief Represents a theme park that contains attractions and visitors.
 *
 * This class manages the park's attractions, visitors, and calculates the total profit
 * and average time spent at the attractions .
 */
class Park {
private:
    std::string name; /**< The name of the park. */
    std::vector<std::shared_ptr<Attraction>> attractions; /**< The list of attractions in the park. */
    std::vector<std::shared_ptr<Visitor>> visitors; /**< The list of visitors in the park. */
    static int totalVisitors; /**< The total number of visitors across all parks. */

public:
    /**
     * @brief Constructs a new Park object.
     *
     * Initializes the park with a given name.
     *
     * @param name The name of the park.
     */
    explicit Park(const std::string& name);

    /**
     * @brief Copy constructor for the Park class.
     *
     * This constructor creates a new park as a copy of an existing one.
     *
     * @param other The park object to copy.
     */
    Park(const Park& other);

    /**
     * @brief Assignment operator for the Park class.
     *
     * This operator assigns one park to another using the copy-and-swap idiom.
     *
     * @param other The park object to assign.
     * @return A reference to the updated park object.
     */
    Park& operator=(Park other);

    /**
     * @brief Swaps the contents of two Park objects.
     *
     * This function exchanges the internal data of two park objects, used by the assignment operator.
     *
     * @param a The first park object.
     * @param b The second park object.
     */
    friend void swap(Park& a, Park& b) noexcept;

    /**
     * @brief Adds an attraction to the park.
     *
     * This function adds a shared pointer to an attraction to the park's attractions list.
     *
     * @param attraction The attraction to add.
     */
    void addAttraction(const std::shared_ptr<Attraction>& attraction);

    /**
     * @brief Adds a visitor to the park.
     *
     * This function adds a shared pointer to a visitor to the park's visitors list.
     *
     * @param visitor The visitor to add.
     */
    void addVisitor(const std::shared_ptr<Visitor>& visitor);

    /**
     * @brief Displays the list of attractions in the park.
     *
     * This function prints out the details of all attractions in the park.
     */
    void showAttractions() const;

    /**
     * @brief Retrieves the list of attractions in the park.
     *
     * @return A constant reference to the vector of attractions.
     */
    [[nodiscard]] const std::vector<std::shared_ptr<Attraction>>& getAttractions() const;

    /**
     * @brief Displays the list of visitors in the park.
     *
     * This function prints out the details of all visitors in the park.
     */
    void showVisitors() const;

    /**
     * @brief Simulates the experience of all visitors visiting the attractions.
     *
     * This function makes each visitor visit all attractions in the park.
     */
    void visitAttractions() const;

    /**
     * @brief Calculates the total profit generated from all attractions.
     *
     * This function computes the total profit based on the number of visitors and the entrance fees.
     *
     * @return The total profit in monetary value.
     */
    [[nodiscard]] double calcTotalProfit() const;

    /**
     * @brief Calculates the average time spent by all visitors in the park.
     *
     * This function computes the average time spent by visitors based on their experiences with the attractions.
     *
     * @return The average time spent by visitors in hours.
     */
    [[nodiscard]] double averageTimeSpent() const;

    /**
     * @brief Retrieves the total number of visitors across all parks.
     *
     * @return The total number of visitors.
     */
    static int getTotalVisitors();

    /**
     * @brief Increments the total number of visitors.
     *
     * This function is used to increment the static count of total visitors.
     */
    static void incrementTotalVisitors();
};

#endif
