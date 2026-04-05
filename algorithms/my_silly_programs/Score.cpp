#include "Score.h"
#include <iostream>

using std::string;
using std::cout;

string Score::getCourseName() const {return courseName;}
double Score::getGrade() const {return grade;}
double Score::getCredit() const {return credit;}
double Score::getWeight() const {return weight;}
double Score::getGPA() const {
    if (grade < 60) {
        cout << "The " << courseName << " is failed!\n";
        return 0.0;
    }
    else {
        return 1.0 + (grade - 60) * 0.1;
    }
}
