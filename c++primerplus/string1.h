#ifndef STRING1_H
#define STRING1_H

#include <iostream>
using std::ostream;
using std::istream;

class String {
private:
    char* str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;
public:
    String(const char * s);
    String();
    String(const String &);
    ~String();
    int length() const {return len;};
    String & Stringlow();
    String & Stringup();
    String & operator=(const String &);
    String & operator=(const char *);
    int has(const char ch);
    char & operator[](int i);
    const char& operator[](int i) const;
    friend bool operator>(const String & s1, const String & s2);
    friend bool operator<(const String & s1, const String & s2);
    friend bool operator==(const String & s1, const String & s2);
    friend String operator+(const String &s1, const String & s2);
    friend String operator+(const char* s1, const String & s2);
    friend istream& operator>>(istream &is, String &s);
    friend ostream& operator<<(ostream &os, const String &s);
    static int howmany();
};

#endif