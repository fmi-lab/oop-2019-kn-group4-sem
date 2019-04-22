#include "WeeklyEvent.h"
#include <string>
#include <iostream>
#include "DateTime.h"
WeeklyEvent::WeeklyEvent(
                         std::string description,
                         DateTime start,
                         unsigned duration,
                         int repetitions
            ): Event(description, start, duration), repetitions(repetitions)
{
    //ctor
}

WeeklyEvent::WeeklyEvent(WeeklyEvent const& other)
    : Event(other), repetitions(other.repetitions)
    {

    }
WeeklyEvent& WeeklyEvent::operator=(WeeklyEvent const& other)
{
    if (this != &other) {
        // this->operator=(other); // *this = other;
        Event::operator=(other);
        this->repetitions = other.repetitions;
    }
    // std::cout << this->getDescription() << std::endl;
    return *this;
}

WeeklyEvent::~WeeklyEvent()
{
    std::cout << "weekly event destructor" << std::endl;
    // no need to call the parent destructor
    // Event::~Event();
}

bool WeeklyEvent::isInProgress(DateTime const& now) const
{
    for (int i = 0; i < repetitions; i++) {
        DateTime repetitionStart = this->start.addMinutes(7 * 24 * 60 * i);
        DateTime end = repetitionStart.addMinutes(duration);
        if (repetitionStart < now  && now < end) {
            return true;
        }
    }
    return false;
}

Event* WeeklyEvent::clone() const {
    return new WeeklyEvent(*this);
}
