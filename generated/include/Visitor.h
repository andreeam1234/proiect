#ifndef VISITOR_H
#define VISITOR_H

#include <string>
#include <memory>
#include "Ticket.h"
#include "Attraction.h"

class Visitor {
    std::string name;
    int age;
    std::shared_ptr<Ticket> ticket;

public:
    explicit Visitor(std::string name, int age, std::shared_ptr<Ticket> ticket);

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] int getAge() const;
    [[nodiscard]] std::shared_ptr<Ticket> getTicket() const;

    void printTicketInfo() const;
    void visitAttraction(const std::shared_ptr<Attraction>& attraction) const;
};

#endif
