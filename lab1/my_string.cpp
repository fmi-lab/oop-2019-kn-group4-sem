#include <iostream>
#include <cstring>
using namespace std;

class MyString {
private:
    char *data;
    int len;
    void copy(char from[]) {
        int fromLen = strlen(from);
        delete [] this->data;
        this->data = new char[fromLen + 1];
        for (int i = 0; i < fromLen; i++) {
            this->data[i] = from[i];
        }
        this->data[fromLen] = '\0';
        this->len = fromLen;
    }

public:
    MyString() {
        this->data = new char[1];
        this->data[0] = '\0';
        this->len = 0;
    }
    MyString(char c, unsigned repetitions) {
        this->data = new char[repetitions + 1];
        for (unsigned i = 0; i < repetitions; i++) {
            this->data[i] = c;
        }
        this->data[repetitions] = '\0';
        this->len = repetitions;
    }
    MyString(char from[]) {
        this->copy(from);
    }
    void setData(char newData[]) {
        this->copy(newData);
    }

    int length() {
        // this is of type (MyString*)
        return this->len;
    }
//    void setLength(int newValue) {
//        this->len = newValue;
//    }
    void concatenate(char source[]) {
        int currentLen = this->length();
        int sourceLen = strlen(source);
        int newLen = currentLen + sourceLen;
        char *newData = new char[newLen + 1];
        // copy existing data
        int index = 0;
        char* existingData = this->data;
        while(*existingData != '\0') {
            newData[index++] = *existingData;
            existingData++;
        }
        // copy source
        while(*source != '\0') {
            newData[index++] = *source;
            source++;
        }
        newData[index] = '\0';
        delete [] this->data;
        this->data = newData;
    }
};

MyString create(char from[]) {
    MyString result;
    int fromLen = strlen(from);
    result.data = new char[fromLen + 1];
    for (int i = 0; i < fromLen; i++) {
        result.data[i] = from[i];
    }
    result.data[fromLen] = '\0';
    return result;
}
int mylen(MyString* str) {
    return strlen(str->data);
}
void mycat(MyString* str, char source[]) {
    int currentLen = mylen(str);
    int sourceLen = strlen(source);
    int newLen = currentLen + sourceLen;
    char *newData = new char[newLen + 1];
    // copy existing data
    int index = 0;
    char* existingData = str->data;
    while(*existingData != '\0') {
        newData[index++] = *existingData;
        existingData++;
    }
    // copy source
    while(*source != '\0') {
        newData[index++] = *source;
        source++;
    }
    newData[index] = '\0';
    delete [] str->data;
    str->data = newData;
}

void mycopy(MyString* str, char source[]) {
   int currentLen = mylen(str);
   int sourceLen = strlen(source);
   if (currentLen < sourceLen) {
      delete [] str->data;
      str->data = new char[sourceLen + 1];
   }
   for (int i = 0; i < sourceLen; i++) {
      str->data[i] = source[i];
   }
   str->data[sourceLen] = '\0';
}

void mycopy(MyString* destination, MyString& source) {
    mycopy(destination, source.data);
}
int main()
{
    MyString c = create("Hello, world!");
    MyString c1("Hello from OOP!");
    cout << mylen(&c1) << endl;
    cout << c1.length() << endl;
    c1.concatenate(" abcd ");
    c1.setData("New data");
    return 0;
}
