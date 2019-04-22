#include "Calendar.h"
#include <cstring>

Calendar::Calendar(const char* name): name(name), events(100) {
    // this->events = DynamicArray<Event>(100);
    /*
    this->events = new Event[numEvents];
    this->numEvents = numEvents;
    for (unsigned i = 0; i < numEvents; i++) {
        this->events[i] = events[i];
    }
    */
}

Calendar::Calendar(Calendar const& other) {
    this->copy(other);
}
void Calendar::copy(Calendar const& other) {
    this->name = other.name;
    for (int i = 0; i < other.events.size(); i++) {
        Event* copy = other.events[i]->clone();
        this->events.push_back(copy);
    }
}

Calendar& Calendar::operator=(Calendar const& other) {
    if (this != &other) {
        this->destroy();
        this->copy(other);
    }
    return *this;
}

Calendar::~Calendar() {
    this->destroy();
}
void Calendar::destroy() {
    for (int i = 0; i < this->events.size(); i++) {
        delete this->events[i];
    }
}
void Calendar::addEvent(Event const& event) {
    Event* copy = new Event(event);
    this->events.push_back(copy);
}
void Calendar::addWeeklyEvent(WeeklyEvent const& weeklyEvent) {
    WeeklyEvent* copy = new WeeklyEvent(weeklyEvent);
    this->events.push_back(copy);
}


