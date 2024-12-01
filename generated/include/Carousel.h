#ifndef CAROUSEL_H
#define CAROUSEL_H

#include "Attraction.h"

class Carousel : public Attraction {
    int maxCapacity;

public:
    explicit Carousel(const std::string& name, double duration, int minHeight, int maxCapacity, int maxVisitors);

    void simulateExperience() const override;
    [[nodiscard]]Carousel *clone() const override;
};

#endif
