#ifndef VISITORTOOSHORTEXCEPTION_H
#define VISITORTOOSHORTEXCEPTION_H

#include <exception>
#include <string>

class VisitorTooShortException : public std::exception {
private:
    std::string message;
public:
    VisitorTooShortException()
        : message_("The visitor is too short to ride this attraction.") {}

    const char* what() const noexcept override {
        return message_.c_str();
    }
};

#endif //VISITORTOOSHORTEXCEPTION_H
