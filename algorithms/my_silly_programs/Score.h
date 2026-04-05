#pragma once

#include <string>

using std::string;

class Score {
private:
    string courseName;
    double grade;
    double credit;
    double weight;
public:
    Score(const string & name, const double & grade, const double & credit, const double weight = 1.0) 
        : courseName(name), grade(grade), credit(credit), weight(weight) {}
    ~Score() = default;
    string getCourseName() const;
    double getGrade() const;
    double getCredit() const;
    double getWeight() const;
    double getGPA() const;
};