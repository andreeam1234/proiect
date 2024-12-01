#ifndef ROLLERCOASTER_h
#define ROLLERCOASTER_h

#include "Attraction.h"

class RollerCoaster : public Attraction {
private:
    int speed;

public:
    explicit RollerCoaster(const std::string& name, double duration, int minHeight, int speed);

    void simulateExperience() const override;
    RollerCoaster *clone() const override;
};

#endif