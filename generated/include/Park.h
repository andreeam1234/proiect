// Park.h
#ifndef PARK_H
#define PARK_H

#include <string>
#include <vector>
#include <memory>
#include "Attraction.h"
#include "Visitor.h"

class Park {
    std::string name;
    std::vector<std::shared_ptr<Attraction>> attractions;
    std::vector<std::shared_ptr<Visitor>> visitors;

public:
    explicit Park(const std::string& name);

    void addAttraction(const std::shared_ptr<Attraction>& attraction);
    void addVisitor(const std::shared_ptr<Visitor>& visitor);
    void showAttractions() const;
    void showVisitors() const;
    void visitAttractions() const;
};

#endif  // PARK_H
