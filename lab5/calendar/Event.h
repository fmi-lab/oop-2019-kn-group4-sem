#ifndef EVENT_H
#define EVENT_H

#include <string>
#include "DateTime.h"

class Event
{
    public:
        Event();
        Event(std::string description, DateTime start, unsigned duration);
        std::string getDescription();
    private:
        std::string description;
        DateTime start;
        unsigned duration;
};

#endif // EVENT_H
