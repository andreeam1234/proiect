#ifndef PARK_H
#define PARK_H

#include <string>
#include <vector>
#include <memory>
#include "Visitor.h"
#include "Attraction.h"

class Park {
private:
    std::string name;
    std::vector<std::shared_ptr<Attraction>> attractions;
    std::vector<std::shared_ptr<Visitor>> visitors;
    static int totalVisitors;

public:
    explicit Park(const std::string& name);

    void addAttraction(const std::shared_ptr<Attraction>& attraction);
    void addVisitor(const std::shared_ptr<Visitor>& visitor);
    void showAttractions() const;
    [[nodiscard]] const std::vector<std::shared_ptr<Attraction>>& getAttractions() const;
    void showVisitors() const;
    void visitAttractions() const;
    [[nodiscard]]double calcTotalProfit() const;
    [[nodiscard]]double averageTimeSpent() const;
    static int getTotalVisitors();
    static void incrementTotalVisitors();
};

#endif // PARK_H
