#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

class Observer {
    public:
    virtual void update(const std::string& eventMessage) = 0;
    virtual ~Observer() = default;
};
#endif //OBSERVER_H