#include <iostream>

#include "MyString.h"
using namespace std;


int main()
{
    MyString s("Hello, world!");
    s.print();
    cout << endl;
    MyString s2 = s;
    s2.convertToUpperCase();
    s2.print();
    cout << endl;
    s.print();
    cout << endl;
    s.copyFrom("Hi, there!");
    s.print();
    cout << endl;
    MyString s3 = s;
    if (s3 != s) {
        cout << "They are equal" << endl;
    }
    else {
        cout << "Not equal" << endl;
    }
    MyString s4("z");
    if (s4 != 'z') {
        cout << "Equal to char" << endl;
    } else {
        cout << "Not equal to char" << endl;
    }
    return 0;
}
