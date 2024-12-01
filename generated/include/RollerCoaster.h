#ifndef ROLLERCOASTER_h
#define ROLLERCOASTER_h

#include "Attraction.h"

class RollerCoaster : public Attraction {
private:
    int speed;

public:
    explicit RollerCoaster(const std::string& name, double duration, int minHeight, int speed, int maxVisitors);

    void screamTest() const {
        std::cout << "People are screaming on the Roller Coaster: " << name << "!\n";
    }

    void simulateExperience() const override;

};

#endif