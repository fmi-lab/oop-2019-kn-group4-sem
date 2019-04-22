#include <iostream>
#include "DateTime.h"
#include "Event.h"
#include "WeeklyEvent.h"
#include "Calendar.h"
using namespace std;

int& operator+=(int& x, const DateTime& d) {
    x += d.getYear();
    return x;
}
int main()
{
    DateTime date(2019, 3, 11);
    cout << date.getHour() << " " << date.getMinutes() << endl;
    DateTime nextDay = date.addMinutes(60 * 25 + 15);
    date += 5;
    cout << date.getYear() << endl;
    date++;
    cout << date.getYear() << endl;
    ++date;
    cout << date.getYear() << endl;
    int test = 5;
    test += date;
    cout << test << endl;
//    cout << date.getHour() << " " << date.getMinutes() << endl;
//    cout << nextDay.getHour() << " " << nextDay.getMinutes() << endl;
    Event e("OOP seminar", DateTime(2019, 3, 11, 15, 15), 105);
    cout << e.getDescription() << endl;
    cout << e.isInProgress(DateTime(2019,3,11,15, 20)) << endl;

    WeeklyEvent w("OOP seminar", DateTime(2019, 2, 19, 15, 15), 105, 15);
    cout << w.getDescription() << endl;
    cout << w.isInProgress(DateTime(2019,2,26,16, 00)) << endl;

    Calendar cal("My Cal");
    cal.addEvent(e);
    cal.addWeeklyEvent(w);

    return 0;
}
