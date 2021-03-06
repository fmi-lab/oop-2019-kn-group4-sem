#include <iostream>
#include "DateTime.h"
#include "Event.h"
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
//    Event e("OOP seminar", DateTime(2019, 3, 11, 15, 15), 105);
//    cout << e.getDescription() << endl;
    return 0;
}
