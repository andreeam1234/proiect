#ifndef ROLLERCOASTER_H
#define ROLLERCOASTER_H

#include "Attraction.h"

/**
 * @brief Represents a RollerCoaster attraction.
 *
 * This class models a roller coaster attraction with a specific speed.
 * It inherits from the Attraction class and provides specific functionalities
 * such as performing a scream test and simulating the roller coaster experience.
 */
class RollerCoaster : public Attraction {
private:
    int speed; /**< The speed of the roller coaster in km/h. */

public:
    /**
     * @brief Constructs a new RollerCoaster object.
     *
     * Initializes the roller coaster with the given parameters.
     *
     * @param name The name of the roller coaster.
     * @param duration The duration of the roller coaster ride.
     * @param minHeight The minimum height required for the ride.
     * @param speed The speed of the roller coaster in km/h.
     * @param maxVisitors The maximum number of visitors allowed on the ride.
     */
    explicit RollerCoaster(const std::string& name, double duration, int minHeight, int speed, int maxVisitors);

    /**
     * @brief Performs a scream test for the roller coaster.
     *
     * This function simulates the thrill of the ride by printing a message
     * about the passengers screaming during the roller coaster experience.
     */
    void screamTest() const;

    /**
     * @brief Clones the RollerCoaster object.
     *
     * Creates a unique pointer to a new RollerCoaster object that is a clone of this one.
     *
     * @return A unique pointer to the new cloned RollerCoaster object.
     */
    [[nodiscard]] std::unique_ptr<Attraction> clone() const override;

    /**
     * @brief Simulates the experience of the roller coaster.
     *
     * This function simulates the thrill and experience of riding the roller coaster.
     */
    void simulateExperience() const override;
};

#endif // ROLLERCOASTER_H
