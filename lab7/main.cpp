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

double multiplyByDouble(int x) {
    cout << "Multiplying " << x << " by 2.5 " << endl;
    return 2.5 * x;
}

int square(int x) {
    return x*x;
}
int sum (int currentTotal, int nextItem) {
    return currentTotal + nextItem;
}
int findMax(int currentMax, int nextItem) {
    if (currentMax < nextItem) {
        return nextItem;
    }
    return currentMax;
}

int main()
{
    DynamicArray<int> intArray;
    intArray.add(10);
    intArray[0] = 5;
    intArray.add(14);
    printFirst(intArray);
    DynamicArray<double> doubles = intArray.mapAll(multiplyByDouble);
    DynamicArray<int> squared = intArray.mapAll(square);

    int total = intArray.reduce(sum, 0);
    int maxElement = intArray.reduce(findMax, intArray[0]);
    cout << "Original array: " << intArray << endl;
    cout << "Mapped to doubles: " << doubles << endl;
    cout << "Max element: " << maxElement << endl;

    return 0;
}
