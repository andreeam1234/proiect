#ifndef VISITOR_H
#define VISITOR_H

#include <string>
#include <memory>
#include "Ticket.h"
#include "Attraction.h"

class Visitor {
    std::string name;
    int age;
    int height;
    std::shared_ptr<Ticket> ticket;
    double timeSpent;

public:
    Visitor(std::string name, int age, int height, std::shared_ptr<Ticket> ticket);

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] int getAge() const;
    [[nodiscard]] int getHeight() const;
    [[nodiscard]] std::shared_ptr<Ticket> getTicket() const;
    [[nodiscard]] double getTimeSpent() const;
    void printTicketInfo() const;
    void visitAttraction(const std::shared_ptr<Attraction>& attraction) const;
    static void visitPark();
};

#endif // VISITOR_H
