#ifndef EVENT_H
#define EVENT_H

#include <string>
#include "DateTime.h"

class Event
{
    public:
        Event();
        Event(std::string description, DateTime start, unsigned duration);
        std::string getDescription() const;
        virtual bool isInProgress(DateTime const& now) const;
        virtual Event* clone() const;
        virtual ~Event() { }

    protected:
        std::string description;
        DateTime start;
        unsigned duration;
    private:
        char* name;
};

#endif // EVENT_H
