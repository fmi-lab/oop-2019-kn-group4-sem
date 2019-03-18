#ifndef MYSTRING_H
#define MYSTRING_H


class MyString
{
    public:
        MyString();
        MyString(char* data);
        MyString(const MyString& other);
        ~MyString();
        void print() const;
        void convertToUpperCase();
        void copyFrom(char* other);
        bool isEqual(const MyString& other) const;
        bool operator==(const MyString& other) const;
        bool operator!=(const MyString& other) const;
        bool operator==(char c) const;
        bool operator!=(char c) const;
        MyString& operator=(const MyString& other);
    protected:

    private:
        void copy(char* other);
        char* data;
};

#endif // MYSTRING_H
