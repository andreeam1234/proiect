#ifndef CAROUSEL_H
#define CAROUSEL_H

#include "Attraction.h"

/**
 * @brief Class representing a carousel attraction.
 *
 * This class derives from the Attraction base class and represents a carousel ride in the amusement park.
 * It includes functionality specific to the carousel, such as simulating the ride experience and spinning around.
 */
class Carousel : public Attraction {
    int maxCapacity; ///< The maximum number of people the carousel can accommodate at once.

public:
    /**
     * @brief Constructor for Carousel.
     *
     * Initializes the Carousel with the given name, duration, minimum height, maximum capacity, and maximum visitors.
     *
     * @param name The name of the carousel.
     * @param duration The duration of the ride in minutes.
     * @param minHeight The minimum height required to enjoy the ride.
     * @param maxCapacity The maximum number of people allowed on the carousel at once.
     * @param maxVisitors The maximum number of visitors allowed at the carousel.
     */
    explicit Carousel(const std::string& name, double duration, int minHeight, int maxCapacity, int maxVisitors);

    /**
     * @brief Simulate the experience of the carousel.
     *
     * This method overrides the base class method to simulate the experience of the carousel ride.
     */
    void simulateExperience() const override;

    /**
     * @brief Simulate the carousel spinning.
     *
     * This function simulates the carousel spinning around and having fun.
     */
    void spinAround() const;

    /**
     * @brief Clone the Carousel object.
     *
     * This function overrides the clone function of the base class to create a unique pointer
     * to a new Carousel object that is a copy of the current one.
     *
     * @return A unique pointer to a newly created Carousel object.
     */
    [[nodiscard]] std::unique_ptr<Attraction> clone() const override;
};

#endif
