#ifndef CALENDAR_H
#define CALENDAR_H

#include <string>
#include <vector>
#include "Event.h"
#include "WeeklyEvent.h"
class Calendar
{
    public:
        Calendar(const char* name = "Calendar");
        Calendar(Calendar const&);
        Calendar& operator=(Calendar const& other);
        ~Calendar();
        void addEvent(Event const& event);
        void addWeeklyEvent(WeeklyEvent const& weeklyEvent);
    protected:

    private:
        std::string name;
        std::vector<Event*> events;
        void copy(Calendar const& other);
        void destroy();
};

#endif // CALENDAR_H
