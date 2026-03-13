#include <iostream>
#include "string1.h"
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

int String::num_strings = 0;

String::String(const char* s) {
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    num_strings++;
}

String::String() {
    len = 0;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String & s) {
    len = s.len;
    str = new char[len + 1];
    strcpy(str, s.str);
    num_strings++;
}

String::~String() {
    --num_strings;
    delete [] str;
}

String & String::operator=(const String &s) {
    if(this == &s) return *this;
    delete [] str;
    len = s.len;
    str = new char[len + 1];
    strcpy(str, s.str);
    return *this;
}

String & String::operator=(const char *s) {
    delete []str;
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    return *this;
}

char& String::operator[](int i) {
    return str[i];
}

const char& String::operator[](int i) const {
    return str[i];
}

bool operator>(const String & s1, const String & s2) {
    return (strcmp(s1.str, s2.str) > 0);
}

bool operator<(const String & s1, const String & s2) {
    return s2 > s1;
}

bool operator==(const String & s1, const String & s2) {
    return (strcmp(s1.str, s2.str) == 0);
}

istream& operator>>(istream &is, String &s) {
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is) s = temp;
    while (is && is.get() != '\n') continue;
    return is;
}

ostream& operator<<(ostream &os, const String &s) {
    return os << s.str;
}

int String::howmany() {
    return num_strings;
}

String operator+(const String & s1, const String & s2) {
    char* temp = new char[s1.len + s2.len + 1];
    strcpy(temp, s1.str);
    strcat(temp, s2.str);
    String result(temp);
    delete [] temp;
    return result;
}

String operator+(const char* s1, const String & s2) {
    char *temp = new char[strlen(s1) + s2.len + 1];
    strcpy(temp, s1);
    strcat(temp, s2.str);
    String result(temp);
    delete [] temp;
    return result;
}

String & String::Stringlow() {
    for (int i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }
    return *this;
}

String & String::Stringup() {
    for (int i = 0; i < len; i++) {
        str[i] = toupper(str[i]);
    }
    return *this;
}

int String::has(char ch) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (tolower(str[i]) == tolower(ch) ) count++;
    }
    return count;
}