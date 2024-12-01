#ifndef MAXVISITORSEXCEEDEDEXCEPTION_H
#define MAXVISITORSEXCEEDEDEXCEPTION_H

#include <exception>
#include <string>

class MaxVisitorsExceededException : public std::exception{
public:
    MaxVisitorsExceededException()
        : message("The maximum number of visitors for this attraction has been exceeded.") {}

    const char* what() const noexcept override {
        return message_.c_str();
    }

private:
    std::string message_;

};


#endif //MAXVISITORSEXCEEDEDEXCEPTION_H
