#include "student.h"
#include <string>
#include <iostream>
#include <iomanip>

using std::string;
using std::cout;
using std::endl;

string Student::get_Name() const {return name;}
int Student::get_Id() const {return id;}
void Student::addScore(const Score & score) {
    scores.push_back(score);
}
const vector<Score>& Student::get_Scores() const{
    return scores;
}
double Student::calculateGPA() {
    double total_credit = 0;
    double total_multisum = 0;
    for (const Score &ele : scores) {
        total_credit += ele.getCredit();
        total_multisum += ele.getCredit() * ele.getGPA();
    }
    return total_multisum / total_credit;
}
void Student::printScores() const {
    cout << std::fixed << std::setprecision(1);
    for (const auto & s : scores) {
        cout << s.getCourseName() << ": " << s.getGrade() << " (学分: " << s.getCredit() << ")\n";
    }

}