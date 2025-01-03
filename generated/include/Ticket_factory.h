#ifndef TICKET_FACTORY_H
#define TICKET_FACTORY_H
#include "Ticket.h"

class TicketFactory {
public:
    [[nodiscard]] virtual Ticket *createTicket() const = 0;

    virtual ~TicketFactory() = default;
};

class StandardTicketFactory : public TicketFactory {
public:
    [[nodiscard]] Ticket *createTicket() const override {
        auto *ticket = new Ticket(50.0, "Standard", true);
        return ticket;
    }
};

class VIPTicketFactory : public TicketFactory {
public:
    [[nodiscard]] Ticket *createTicket() const override {
        auto *ticket = new Ticket(150.0, "VIP", true);
        return ticket;
    }
};
#endif //TICKET_FACTORY_H
