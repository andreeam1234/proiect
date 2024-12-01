#include "Attraction.h"

Attraction::Attraction(const std::string& name, double duration, int minHeight)
    : name(name), duration(duration), minHeight(minHeight) {}

std::ostream &operator<<(std::ostream &os, const Attraction &attraction) {
    os << "Attraction Name: " << attraction.name << "\n"
    << ", Duration: " << attraction.duration << "minutes\n"
    << ", Minimum Height: " << attraction.minHeight << "cm\n";
    return os;
}
