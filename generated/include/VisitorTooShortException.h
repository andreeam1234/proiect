#ifndef VISITORTOOSHORTEXCEPTION_H
#define VISITORTOOSHORTEXCEPTION_H

#include <exception>
#include <string>

/**
 * @brief Exception thrown when a visitor is too short for an attraction.
 *
 * This exception is thrown when a visitor's height is below the minimum height requirement
 * for an attraction.
 */
class VisitorTooShortException : public std::exception {
public:
    /**
     * @brief Returns the error message for the exception.
     *
     * @return A C-string with the error message.
     */
    [[nodiscard]] const char *what() const noexcept override {
        return "The visitor is too short for this attraction!";
    }
};

#endif // VISITORTOOSHORTEXCEPTION_H
