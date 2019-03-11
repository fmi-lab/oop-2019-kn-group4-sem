#ifndef CALENDAR_H
#define CALENDAR_H

#include <string>
#include "Event.h"

class Calendar
{
    public:
        Calendar();
        Calendar(std::string name);

    protected:

    private:
        std::string name;
        Event events[20];
        unsigned numEvents;
};

#endif // CALENDAR_H
