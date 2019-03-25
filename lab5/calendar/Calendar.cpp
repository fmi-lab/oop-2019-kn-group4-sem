#include "Calendar.h"
#include <cstring>

Calendar::Calendar(const char* name/*, Event* events, unsigned numEvents */) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    /*
    this->events = new Event[numEvents];
    this->numEvents = numEvents;
    for (unsigned i = 0; i < numEvents; i++) {
        this->events[i] = events[i];
    }
    */
}

void Calendar::copy(Calendar const& other) {
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->events = new Event[other.numEvents];
    for (unsigned i = 0; i < other.numEvents; i++) {
        this->events[i] = other.events[i];
    }
    this->numEvents = other.numEvents;
}
Calendar::Calendar(Calendar const& other) {
    this->copy(other);
}

Calendar& Calendar::operator=(Calendar const& other) {
    if (this != &other) {
        delete [] name;
        delete [] events;
        this->copy(other);
    }
    return *this;
}

Calendar::~Calendar() {
    delete [] name;
    delete [] events;
}

void Calendar::addEvent(Event const& event) {
    Event* copiedEvents = new Event[this->numEvents + 1];
    for (unsigned i = 0; i < this->numEvents; i++) {
        copiedEvents[i] = this->events[i];
    }
    copiedEvents[this->numEvents] = event;
    this->numEvents++;
    delete [] this->events;
    this->events = copiedEvents;
}



