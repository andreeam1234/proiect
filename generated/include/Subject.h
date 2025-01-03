#ifndef SUBJECT_H
#define SUBJECT_H
#include "Observer.h"
#include <memory>

class Subject {
public:
    virtual void addObserver(const std::shared_ptr<Observer>& observer) = 0;
    virtual void removeObserver(const std::shared_ptr<Observer>& observer) = 0;
    virtual void notifyObservers(const std::string& eventMessage) = 0;
    virtual ~Subject() = default;
};


#endif //SUBJECT_H
