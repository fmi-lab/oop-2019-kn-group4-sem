#ifndef WEEKLYEVENT_H
#define WEEKLYEVENT_H

#include <string>
#include "Event.h"
#include "DateTime.h"
class WeeklyEvent: public Event
{
    public:
        WeeklyEvent();
        WeeklyEvent(std::string description,
                     DateTime start,
                     unsigned duration,
                     int repetitions);
        WeeklyEvent(WeeklyEvent const&);
        WeeklyEvent& operator=(WeeklyEvent const&);
        ~WeeklyEvent();
        bool isInProgress(DateTime const& now) const;
    protected:

    private:
        int repetitions;
};

#endif // WEEKLYEVENT_H
