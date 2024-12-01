#ifndef ROLLERCOASTER_h
#define ROLLERCOASTER_h

#include "Attraction.h"

class RollerCoaster : public Attraction {
private:
    int speed;

public:
    explicit RollerCoaster(const std::string& name, double duration, int minHeight, int speed, int maxVisitors);

    void simulateExperience() const override;
    [[nodiscard]]RollerCoaster *clone() const override;
};

#endif