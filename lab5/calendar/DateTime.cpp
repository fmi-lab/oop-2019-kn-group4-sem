#include "DateTime.h"
bool DateTime::isValidHour(unsigned hours) {
    return hours < 24;
}
bool DateTime::isValidMinutes(unsigned minutes) {
    return minutes < 60;
}
DateTime::DateTime()
{
    this->year = 0;
    month = 1;
    day = 1;
    hours = 0;
    minutes = 0;
}

DateTime::DateTime(unsigned _year, unsigned month, unsigned day,
                 unsigned hours, unsigned minutes)
{
    year = _year;
    this->month = month;
    this->day = day;
    if (isValidHour(hours)) {
        this->hours = hours;
    } else {
        this->hours = 0;
    }
    if (isValidMinutes(minutes)) {
        this->minutes = minutes;
    } else {
        this->minutes = 0;
    }
}

unsigned DateTime::getYear() const {
    return year;
}

unsigned DateTime::getMonth() {
    return month;
}
unsigned DateTime::getDay() {
    return day;
}

unsigned DateTime::getHour() {
    return hours;
}
unsigned DateTime::getMinutes() {
    return minutes;
}

void DateTime::setYear(unsigned year) {
    this->year = year;
}

void DateTime::setMonth(unsigned month) {
    this->month = month;
}
void DateTime::setDay(unsigned day) {
    this->day = day;
}
void DateTime::setHour(unsigned hour) {
    if (isValidHour(hour)) {
        this->hours = hour;
    }
}

void DateTime::setMinutes(unsigned minutes) {
    if (isValidMinutes(minutes)) {
        this->minutes = minutes;
    }
}

DateTime& DateTime::operator+=(unsigned years) {
    this->year += years;
    return *this;
}

DateTime& DateTime::operator++() {
    this->year += 1;
    return *this;
}

DateTime DateTime::operator++(int) {
    DateTime old = *this;
    this->year+=1;
    return old;
}
DateTime DateTime::addMinutes(unsigned minutes) {
    DateTime result;
    unsigned newMinutes = this->minutes + minutes;
    if (newMinutes < 60) {
        result.setMinutes(newMinutes);
    } else {
        result.setMinutes(newMinutes % 60);
        unsigned newHours = this->hours + newMinutes / 60;
        if (newHours < 24) {
            result.setHour(newHours);
        } else {
            result.setHour(newHours % 24);
            unsigned newDays = this->day + newHours / 24;
            if (newDays < 31) {
                result.setDay(newDays);
            } else {
                result.setDay(newDays % 30 + 1);
                unsigned newMonth = this->month + newDays / 30;
                if (newMonth <= 12) {
                    result.setMonth(newMonth);
                } else {
                    result.setMonth(newMonth % 12 + 1);
                    result.setYear(this->year + newMonth / 12);
                }
            }
        }
    }

    return result;
}
