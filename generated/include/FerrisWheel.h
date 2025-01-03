#ifndef FERRISWHEEL_H
#define FERRISWHEEL_H

#include "Attraction.h"

/**
 * @brief Class representing a Ferris Wheel attraction.
 *
 * This class derives from the Attraction base class and represents a Ferris Wheel
 * ride in the amusement park. It includes functionality specific to the Ferris Wheel,
 * such as simulating the ride experience and enjoying the view.
 */
class FerrisWheel : public Attraction {
private:
    int numberCabins; ///< The number of cabins on the Ferris Wheel.

public:
    /**
     * @brief Constructor for FerrisWheel.
     *
     * Initializes the Ferris Wheel with the given name, duration, minimum height,
     * number of cabins, and maximum visitors.
     *
     * @param name The name of the Ferris Wheel.
     * @param duration The duration of the ride in minutes.
     * @param minHeight The minimum height required to enjoy the ride.
     * @param numberCabins The number of cabins on the Ferris Wheel.
     * @param maxVisitors The maximum number of visitors allowed at the Ferris Wheel.
     */
    FerrisWheel(const std::string &name, double duration, int minHeight, int numberCabins, int maxVisitors);

    /**
     * @brief Simulate the experience of the Ferris Wheel.
     *
     * This method overrides the base class method to simulate the experience of the
     * Ferris Wheel ride.
     */
    void simulateExperience() const override;

    /**
     * @brief Enjoy the view from the Ferris Wheel.
     *
     * This function simulates the experience of enjoying the view while riding the
     * Ferris Wheel.
     */
    void enjoyView() const;

    /**
     * @brief Clone the Ferris Wheel object.
     *
     * This function overrides the clone function of the base class to create a unique pointer
     * to a new FerrisWheel object that is a copy of the current one.
     *
     * @return A unique pointer to a newly created FerrisWheel object.
     */
    [[nodiscard]] std::unique_ptr<Attraction> clone() const override;
};

#endif //FERRISWHEEL_H
