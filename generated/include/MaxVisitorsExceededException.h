#ifndef MAXVISITORSEXCEEDEDEXCEPTION_H
#define MAXVISITORSEXCEEDEDEXCEPTION_H

#include <exception>

/**
 * @brief Exception thrown when the maximum number of visitors for an attraction is exceeded.
 *
 * This exception is used to handle the situation when the number of visitors for an
 * attraction exceeds its maximum allowed capacity.
 */
class MaxVisitorsExceededException : public std::exception {
public:
    /**
     * @brief Returns the error message for the exception.
     *
     * This method overrides the what() function from the std::exception class and
     * provides a specific error message for the MaxVisitorsExceededException.
     *
     * @return A constant character pointer to the error message.
     */
    [[nodiscard]] const char *what() const noexcept override {
        return "The maximum number of visitors for this attraction has been exceeded!";
    }
};

#endif //MAXVISITORSEXCEEDEDEXCEPTION_H
