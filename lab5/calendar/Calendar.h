#ifndef CALENDAR_H
#define CALENDAR_H

#include "Event.h"

class Calendar
{
    public:
        Calendar(const char* name = "Calendar");
        Calendar(Calendar const&);
        Calendar& operator=(Calendar const& other);
        ~Calendar();
        void addEvent(Event const& event);
    protected:

    private:
        char* name;
        Event* events;
        unsigned numEvents;
        void copy(Calendar const& other);
};

#endif // CALENDAR_H
