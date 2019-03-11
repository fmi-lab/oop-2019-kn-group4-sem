#ifndef DATETIME_H
#define DATETIME_H


class DateTime
{
    public:
        DateTime();
        DateTime(unsigned year, unsigned month, unsigned day,
                 unsigned hours = 0, unsigned minutes = 0);
        unsigned getYear();
        unsigned getMonth();
        unsigned getDay();
        unsigned getHour();
        unsigned getMinutes();

        void setYear(unsigned year);
        void setMonth(unsigned month);
        void setDay(unsigned day);
        void setHour(unsigned hour);
        void setMinutes(unsigned minutes);

        DateTime addMinutes(unsigned minutes);
    private:
        unsigned year, month, day;
        unsigned hours, minutes;
        bool isValidHour(unsigned hour);
        bool isValidMinutes(unsigned minutes);
};

#endif // DATETIME_H
