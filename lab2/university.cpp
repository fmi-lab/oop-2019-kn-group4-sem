#include <iostream>
#include <string>
#include <cstring> // strlen, strcpy
using namespace std;

class Date {
private:
    unsigned year;
    unsigned month;
    unsigned day;

public:
    Date() {
        year = 1970;
        month = 1;
        day = 1;
    }
    Date(unsigned year, unsigned month, unsigned day) {
        if (isValidDate(year, month, day)) {
            this->year = year;
            this->month = month;
            this->day = day;
        } else {
            cerr << "Invalid Date in constructor" << endl;
            this->year = 1970;
            this->month = 1;
            this->day = 1;
        }
    }
    bool isValidDate(unsigned year, unsigned month, unsigned day) {
        if (month < 1 || month > 12) {
            cerr << "Invalid month";
            return false;
        }
        if (day < 1 || day > 31) {
            cerr << "Invalid day";
            return false;
        }
        if (day == 31) {
            switch (month) {
            case 2:
            case 4:
            case 6:
            case 9:
            case 11:
                return false;
            }
        }
        if (month == 2) {
            bool isLeap = isLeapYear(year);
            if (day == 30 || (day == 29 && !isLeap)) {
                return false;
            }
        }
        return true;
    }
    bool isLeapYear(unsigned year) {
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    }

    unsigned getYear() {
        return this->year;
    }
    void setYear(unsigned newYear) {
        year = newYear;
    }
    unsigned getMonth() {
        return this->month;
    }
    void setMonth(unsigned newMonth) {
        if (isValidDate(year, newMonth, day)) {
            this->month = newMonth;
        } else {
            cerr << "Invalid month in setter" << endl;
        }
    }
    unsigned getDay() {
        return this->day;
    }
    void setDay(unsigned newDay) {
        if(isValidDate(year, month, newDay)) {
            this->day = newDay;
        } else {
            cerr << "Invalid day in setter" << endl;
        }
    }
};

class Student {
    static int studentCounter;
    string firstName;
    string lastName;
    int fn;
    Date dateOfBirth;
    Date enrollmentDate;

public:
    Student() {
        firstName = "";
        lastName = "";
        fn = studentCounter;
        studentCounter++;
        dateOfBirth = Date();
        enrollmentDate = Date();
    }
    Student(string firstName, string lastName,
            Date dateOfBirth, Date enrollmentDate)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->dateOfBirth = dateOfBirth;
        this->enrollmentDate = enrollmentDate;
        fn = studentCounter;
        studentCounter++;
    }

    int getFN() {
        return fn;
    }

    string getFirstName() {
        return firstName;
    }
    void setFirstName(string newFirstName) {
        this->firstName = newFirstName;
    }

    string getLastName() {
        return lastName;
    }
    void setLastName(string newLastName) {
        this->lastName = newLastName;
    }

    Date getDateOfBirth() {
        return dateOfBirth;
    }
    void setDateOfBirth(Date newDateOfBirth) {
        this->dateOfBirth = newDateOfBirth;
    }
};
int Student::studentCounter = 0;


class Section {
    Student students[];
    int numStudents;
};

class Major {
    string name;
    Section sections[];
    int numSections;
};

class Department {
    string name;
    Major majors[];
    int numMajors;
};

class University {
    string name;
    Department departments[];
    int numDepartments;
};
int main()
{
    Student s1;
    Student s2;
    Student s3;
    cout << "S1: " << s1.getFN() << endl;
    cout << "S2: " << s2.getFN() << endl;
    cout << "S3: " << s3.getFN() << endl;
}
