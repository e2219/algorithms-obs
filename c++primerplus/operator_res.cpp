#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

class Time{
private:
    int hours;
    int minutes;
public:
    Time() {hours = minutes = 0;};
    Time(int h, int m);
    Time operator+(const Time &t);
    Time& operator+=(const Time &t);
    Time operator*(double mult) const;
    friend Time operator*(double mult, const Time &t);
    friend ostream& operator<<(ostream & os, const Time & t);
};

Time::Time(int h, int m) {
    hours = h;
    minutes = m;
}

Time Time::operator+(const Time & t) {
    Time sum;
    sum.hours = hours + t.hours + (minutes + t.minutes) / 60;
    sum.minutes = (minutes + t.minutes) % 60;
    return sum; 
}

Time& Time::operator+=(const Time & t) {
    hours += t.hours + (minutes + t.minutes) / 60;
    minutes = (minutes + t.minutes) % 60;
    return *this;
}



Time Time::operator*(double mult) const {
    Time result;
    long totalminutes = hours * mult * 60 + minutes * mult;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}

Time operator*(double mult, const Time & t) {
    Time result;
    long totalminutes = t.hours * mult * 60 + t.minutes * mult;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
    //return t * mult;(使用成员函数的重载)
}

ostream& operator<<(ostream& os, const Time & t) {
    return os << t.hours << " hours. " << t.minutes << " minutes."; 
}


int main() {
    Time coding(2, 40);
    Time fixing = {3, 55};
    Time sleep = Time(7, 30);
    Time total = coding + fixing;
    cout << total;
    total += sleep;
    cout << total;
    cout << endl;
    Time adjusted = 1.5 * total; 
    cout << "adjusted time: " << adjusted << total;
}