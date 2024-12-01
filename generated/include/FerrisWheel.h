#ifndef FERRISWHEEL_H
#define FERRISWHEEL_H

#include "Attraction.h"


class FerrisWheel : public Attraction {
private:
    int numberCabins;
public:
    FerrisWheel(const std::string& name, double duration, int minHeight, int numberCabins, int maxVisitors);

    void simulateExperience() const override;
    FerrisWheel *clone() const override;
};

#endif //FERRISWHEEL_H
