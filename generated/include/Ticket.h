#ifndef TICKET_H
#define TICKET_H

#include <string>

class Ticket {
    std::string type;
    double price;
    bool isValid;

public:
    Ticket(double price, const std::string& type, bool isValid);

    [[nodiscard]] std::string getType() const;
    [[nodiscard]] double getPrice() const;
    [[nodiscard]] bool isValidTicket() const;

    void validate() const;  // Funcție ce aruncă excepție
    void printInfo() const;
};

#endif
