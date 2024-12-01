#ifndef TICKET_H
#define TICKET_H

#include <string>

class Ticket {
    double price;
    std::string type;

public:
    Ticket(double price, std::string type);

    [[nodiscard]] double getPrice() const;
    [[nodiscard]] std::string getType() const;
};

#endif