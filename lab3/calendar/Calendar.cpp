#include "Calendar.h"

Calendar::Calendar() {
    name = "";
    numEvents = 0;
}
Calendar::Calendar(std::string name) {
    this->name = name;
    numEvents = 0;
}
