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
    Attraction(const Attraction& other);
    Attraction& operator=(Attraction other);

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] double getDuration() const;
    [[nodiscard]] int getMinHeight() const;
    [[nodiscard]] int getMaxVisitors() const;
    [[nodiscard]] int getCurrentVisitors() const;

    virtual void simulateExperience() const;
    void addVisitor();
    virtual ~Attraction() = default;

    virtual void describe() const;
    friend std::ostream& operator<<(std::ostream& os, const Attraction& attraction);

    friend void swap(Attraction& first, Attraction& second) noexcept;
};

#endif
