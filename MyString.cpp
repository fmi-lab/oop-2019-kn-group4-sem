#include "MyString.h"
#include <cstring>
#include <iostream>
MyString::MyString()
{
    this->data = new char[1];
    this->data[0] = '\0';
}

MyString::MyString(const MyString& other)
{
    this->copy(other.data);
}
MyString::MyString(char* data)
{
    this->copy(data);
}

void MyString::convertToUpperCase() {
    for (int i = 0; i < strlen(this->data); i++) {
        if (this->data[i] >= 'a' && this->data[i] <= 'z') {
            this->data[i] += 'A' - 'a';
        }
    }
}

MyString::~MyString()
{
    delete[] this->data;
}

void MyString::print() const {
    std::cout << this->data;
}

void MyString::copyFrom(char* other)
{
    delete [] this->data;
    this->copy(other);
}

MyString& MyString::operator=(const MyString& other)
{
    if (this != &other) {
        delete [] this->data;
        this->copy(other.data);
    }
    return *this;
}

void MyString::copy(char* data)
{
    this->data = new char[strlen(data) + 1];
    char* copyHelper = this->data;
    while (*data != '\0') {
        *copyHelper = *data;
        copyHelper++;
        data++;
    }
    *copyHelper = '\0';
}
bool MyString::operator==(char c) const
{
    return strlen(this->data) == 1 && this->data[0] == c;
}
bool MyString::operator!=(char c) const
{
    return !this->operator==(c);
}

bool MyString::operator==(const MyString& other) const
{
    return this->isEqual(other);
}
bool MyString::operator!=(const MyString& other) const
{
    return !((*this)==other);
}

bool MyString::isEqual(const MyString& other) const
{
    int thisLen = strlen(this->data);
    int otherLen = strlen(other.data);
    if (thisLen != otherLen) {
        return false;
    }
    for (int i = 0; i < thisLen; i++) {
        if (this->data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}
