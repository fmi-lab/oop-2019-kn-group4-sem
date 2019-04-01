#include <iostream>
#include <ostream>
#include "DynamicArray.h"

using namespace std;

class Point {
    int x;
    int y;
    public:
        Point(int x = 0, int y = 0): x(x), y(y) {}
        void print() const {
            cout << x << y << endl;
        }

        friend ostream& operator<<(ostream& out, Point const& p);
};

ostream& operator<<(ostream& out, Point const& p) {
    out << p.x << " " << p.y << endl;
    return out;
}

template <typename T>
void printFirst(DynamicArray<T> const& arr) {
    cout << "In print first: ";
    /// arr[0] = 3; - not allowed on const
    cout << arr[0] << endl;
}

int main()
{
    DynamicArray<int> intArray;
    DynamicArray<Point> pointArray;
    intArray.add(10);
    pointArray.add(Point(2,3));
    intArray[0] = 5;
    intArray.add(14);
    printFirst(intArray);
    printFirst(pointArray);
    cout << intArray << endl;
    return 0;
}
