#ifndef MAXVISITORSEXCEEDEDEXCEPTION_H
#define MAXVISITORSEXCEEDEDEXCEPTION_H

#include <exception>


class MaxVisitorsExceededException : public std::exception{
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "The maximum number of visitors for this attraction has been exceeded!";
    }
};

#endif //MAXVISITORSEXCEEDEDEXCEPTION_H
