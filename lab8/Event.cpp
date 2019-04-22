#include <string>
#include "Event.h"
#include "DateTime.h"

Event::Event() {
    description = "";
    start = DateTime(2019, 1, 1);
    duration = 60;
}
Event::Event(std::string description, DateTime start, unsigned duration) {
    this->description = description;
    this->start = start;
    this->duration = duration;
}

std::string Event::getDescription() const {
    return description;
}

bool Event::isInProgress(DateTime const& now) const
{
    DateTime end = start.addMinutes(duration);
    return start < now && now < end;
}

Event* Event::clone() const {
    return new Event(*this);
}
