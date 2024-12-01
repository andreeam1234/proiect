#ifndef FERRISWHEEL_H
#define FERRISWHEEL_H

#include "Attraction.h"


class FerrisWheel : public Attraction {
private:
    int numberCabins;
public:
    FerrisWheel(const std::string& name, double duration, int minHeight, int numberCabins, int maxVisitors);

    void simulateExperience() const override;
    void enjoyView() const {
        std::cout << "Visitors are enjoying the view on the Ferris Wheel: " << name << "!\n";
    }

};

#endif //FERRISWHEEL_H
