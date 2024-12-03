#ifndef ATTRACTION_H
#define ATTRACTION_H

#include <string>
#include <iostream>
#include <memory>

/**
 * @class Attraction
 * @brief Represents a generic attraction in an amusement park.
 */
class Attraction {
private:
    std::string name;       ///< Name of the attraction.
    double duration;        ///< Duration of the attraction experience in minutes.
    int minHeight;          ///< Minimum height required to participate in centimeters.
    int maxVisitors;        ///< Maximum number of visitors allowed at a time.
    int currentVisitors;    ///< Current number of visitors present.

public:
    /**
     * @brief Constructs an Attraction object.
     * @param name Name of the attraction.
     * @param duration Duration of the experience in minutes.
     * @param minHeight Minimum height required to participate in centimeters.
     * @param maxVisitors Maximum number of visitors allowed at a time.
     */
    Attraction(const std::string& name, double duration, int minHeight, int maxVisitors);

    /**
     * @brief Gets the name of the attraction.
     * @return Name of the attraction as a string.
     */
    [[nodiscard]] std::string getName() const;

    /**
     * @brief Gets the duration of the attraction experience.
     * @return Duration in minutes as a double.
     */
    [[nodiscard]] double getDuration() const;

    /**
     * @brief Gets the minimum height required for the attraction.
     * @return Minimum height in centimeters as an integer.
     */
    [[nodiscard]] int getMinHeight() const;

    /**
     * @brief Gets the maximum number of visitors allowed at the attraction.
     * @return Maximum number of visitors as an integer.
     */
    [[nodiscard]] int getMaxVisitors() const;

    /**
     * @brief Gets the current number of visitors present at the attraction.
     * @return Current number of visitors as an integer.
     */
    [[nodiscard]] int getCurrentVisitors() const;

    /**
     * @brief Simulates the attraction experience.
     */
    virtual void simulateExperience() const = 0;

    /**
     * @brief Increments the current visitor count by one.
     */
    void addVisitor();

    /**
     * @brief Creates a copy of the Attraction object.
     * @return A unique pointer to a cloned Attraction object.
     */
    [[nodiscard]] virtual std::unique_ptr<Attraction> clone() const = 0;

    /**
     * @brief Virtual destructor for the Attraction class.
     */
    virtual ~Attraction() = default;

    /**
     * @brief Describes the attraction.
     * @details Outputs information about the attraction to the console.
     */
    virtual void describe() const;

    /**
     * @brief Overloads the output stream operator for Attraction.
     * @param os Reference to the output stream.
     * @param attraction Reference to the Attraction object.
     *
     */
    friend std::ostream& operator<<(std::ostream& os, const Attraction& attraction);
};

#endif
