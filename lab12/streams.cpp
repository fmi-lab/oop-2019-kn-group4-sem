#include <iostream>
#include "RunningAverage.h"
#include "Sequence.h"
#include "ConstantSequence.h"
#include "ArithmeticProgression.h"
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct Rational {
    int x;
    int y;
};

int main()
{
    /** TEXT FILES **/

    /** open file for writing (output) **/
    // constructor with filename
    ofstream of("test.txt", ios::trunc);
    // or default-construct and open explicitly
    ofstream of2;
    of2.open("test2.txt", ios::app);

    /** use file **/
    of << "Hello world";
    of2 << 2 << 3 << 5;

    /** close file **/
    of.close();
    of2.close();

    /** open file for reading (input) **/
    ifstream f("test.txt");
    int n;
    vector<int> numbers;
    /** use file **/
    f >> n;
    for (int i = 0; i < n; i++) {
        int number;
        f >> number;
        numbers.push_back(number);
    }
    /** close file **/
    f.close();
    /** open another file for reading (input) **/
    f.open("test2.txt");
    string input;
    string allText;
    /** use file **/
    // getline returns the istream passed to it
    // this is equivalent to
    //    while(f) { <- f is converted to bool, this checks if the stream is "good"
    //        getline(f, input, ',');
    //        if (f) {
    //            ...
    //        }
    //    }
    while(getline(f, input, ',')) {
        // splitting input by ',' - the new lines are included as parts of the strings now
        cout << input << endl << ";;;;;;;;;;";
        allText += input;
    }
    /** close file **/
    f.close();

    cout << allText << endl;
    cout << "........." << endl;
    stringstream ss(allText);
    // stringstream reads from a string instead of a file
    // all stream operations work the same way
    while (getline(ss, input, 'a')) {
        cout << input << endl;
    }

    /** Binary files **/
    ofstream obin("test.bin", ios::trunc | ios::binary);
    n = 5;
    Rational r;
    r.x = 7;
    r.y = 11;
    // take sizeof(Rational) bytes from address &r (treated as char*)
    // and write them in the file
    obin.write((char*)&r, sizeof(Rational));
    for (int i = 0; i < 5; i++) {
        obin.write((char*)&i, sizeof(i));
    }
    obin.close();

    int x = 8;
    Rational r2;
    cout << endl << "Old x: " << x;
    ifstream ibin("test.bin", ios::binary);
    // take sizeof(Rational) bytes from the file
    // and put them in the address where r2 is stored
    // it is our responsibility to make sure r2 is of type Rational
    // ibin.read((char*)&x, sizeof(Rational)); // tries to access memory outside of x
    ibin.read((char*)&r2, sizeof(Rational));

    // seek to the last int in the file
    // note the cast to (int) - sizeof(int) returns unsigned, which messes with the *
    ibin.seekg(-1 * (int)sizeof(int), ios::end);
    // read sizeof(int) bytes and put them where x is stored
    ibin.read((char*)&x, sizeof(int));

    cout << endl << "New x: " << x;
    ibin.close();
    return 0;
}
