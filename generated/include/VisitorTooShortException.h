#ifndef VISITORTOOSHORTEXCEPTION_H
#define VISITORTOOSHORTEXCEPTION_H

#include <exception>
#include <string>

class VisitorTooShortException : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "The visitor is too short for this attraction!";
    }
};

#endif // VISITORTOOSHORTEXCEPTION_H
