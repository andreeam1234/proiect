#ifndef CAROUSEL_H
#define CAROUSEL_H

#include "Attraction.h"

class Carousel : public Attraction {
    int maxCapacity;

public:
    explicit Carousel(const std::string& name, double duration, int minHeight, int maxCapacity, int maxVisitors);

    void simulateExperience() const override;
    void spinAround() const {
        std::cout << "The Carousel " << name << " is spinning and kids are having fun!\n";
    }


};

#endif
