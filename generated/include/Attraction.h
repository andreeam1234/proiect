#ifndef ATTRACTION_H
#define ATTRACTION_H

#include <string>
#include <iostream>

class Attraction {
protected:
    std::string name;
    double duration;
    int minHeight;

public:
    explicit Attraction(const std::string& name, double duration, int minHeight);
    virtual ~Attraction() = default;

    [[nodiscard]] std::string getName() const {
        return name;
    };
    [[nodiscard]] double getDuration() const {
        return duration;
    }
    [[nodiscard]] int getMinHeight() const {
        return minHeight;
    }

    virtual void simulateExperience() const = 0;
    virtual Attraction* clone() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Attraction& attraction);
};

#endif