#ifndef ATTRACTION_H
#define ATTRACTION_H

#include <string>
#include <iostream>

class Attraction {
protected:
    std::string name;
    double duration;
    int minHeight;
    int maxVisitors;
    int currentVisitors;

public:
    Attraction(const std::string& name, double duration, int minHeight, int maxVisitors);
    virtual ~Attraction() = default;

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] double getDuration() const;
    [[nodiscard]] int getMinHeight() const;
    [[nodiscard]] int getMaxVisitors() const;
    [[nodiscard]] int getCurrentVisitors() const;

    virtual void simulateExperience() const;
    void addVisitor();
    [[nodiscard]]virtual Attraction* clone() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Attraction& attraction);
};

#endif
