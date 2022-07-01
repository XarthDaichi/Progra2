//
// Created by Xarthy on 0013 May 13, 2022.
//

#ifndef PROGRA2_PROJECT_1_DELTA_TICKETFILEMANAGER_H
#define PROGRA2_PROJECT_1_DELTA_TICKETFILEMANAGER_H
#include "SingletonFileManager.h"
#include "Ticket.h"

class TicketFileManager final : public SingletonFileManager<TicketFileManager> {
private:
    Container<Ticket>* tickets;
    char inputType;
public:
    TicketFileManager(const char c);
    virtual ~TicketFileManager();

    void setInputType(char inputType);

    Container<Ticket>* getTickets();

    static ostream& write(ostream& out, const Ticket& ticket);
    static istream& read(istream& in, Ticket& ticket);
};


#endif //PROGRA2_PROJECT_1_DELTA_TICKETFILEMANAGER_H
