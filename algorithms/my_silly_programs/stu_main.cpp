#include "student.h"
#include "Score.h"
#include "file_io.h"
#include <iostream>
#include <iomanip>
#include <limits>

using std::cout;
using std::cin;

int main() {
        vector<Student> students;
        cout << "Welcome to my silly programs!\n";
        cout << "You can choose these following choice:\n";
        students = FileIO::readStudentFromFile("data.txt");
        bool running = true;
    while (running) {
        cout << "\n";
        cout << "------------------------------------\n";
        cout << "1. Show all\n";
        cout << "2. Append a student\n";
        cout << "3. Append score\n";
        cout << "4. calculate GPA\n";
        cout << "5. Save in the file\n";
        cout << "0. Exit\n";
        cout << "------------------------------------\n";
        int choice;
        if (!(cin >> choice)) {
            cout << "Invaild input! Please enter a Integet\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch(choice){
            case 1: {
                for (auto & student : students) {
                    cout << student.get_Id() << "," << student.get_Name() << std::endl;
                    for (const auto &score : student.get_Scores()) {
                        cout << score.getCourseName() << "," << score.getGrade() << ",";
                        cout << score.getCredit() << "," << score.getWeight() << std::endl;
                    }
                }
                break;
            }
            case 2: {
                string name;
                int id;
                cout << "Name: "; getline(cin, name);
                cout << "Id: "; cin >> id;
                Student student(id, name);
                students.push_back(student);
                cout << std::endl;
                break;
            }
            case 3: {
                while(true) {
                    cout << "Enter the id you want to append score. ";
                    int id;
                    int found = 0;
                    if (!(cin >> id)) {
                        cout << "invalid input!" << std::endl;
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Please try it again!\n";
                        continue;
                    }
                    for (auto & student : students) {
                        if (id == student.get_Id()) {
                            found = 1;
                            string coursename;
                            double grade, credit, weight;
                            cout << "CourseName: "; cin >> coursename;
                            cout << "The grade, credit and weight(split by space): "; 
                            if (cin >> grade >> credit >> weight) {
                                ;
                            }
                            else {
                                cin.clear();
                                cin.ignore(10000, '\n');
                                break;
                            }
                            Score score(coursename, grade, credit, weight);
                            student.addScore(score);
                            
                            break;
                        }
                    }
                    if (found) {
                        cout << "succeed enter!\n";
                        break;
                    }
                    else {
                        cout << "Cannot found the student or invalid data! Enter 1 to try it again, or other numbers to go back to the menu.\n";
                        int tryagain;
                        cin >> tryagain;
                        if (tryagain == 1) {
                            continue;
                        }
                        else break;
                    }
                }
                break;
            }
            case 4: {
                while(true) {
                    cout << "Enter the id you want to calculate GPA. ";
                    int id;
                    int found = 0;
                    if (!(cin >> id)) {
                        cout << "invalid input!" << std::endl;
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Please try it again!\n";
                        continue;
                    }
                    for (auto & student : students) {
                        if (id == student.get_Id()) {
                            found = 1;
                            double GPA = student.calculateGPA();
                            cout << std::fixed << std::setprecision(4) << GPA << std::endl;
                            cout.unsetf(std::ios::fixed);
                            cout << std::setprecision(1);
                            break;
                        }
                    }
                    if (found) {
                        break;
                    }
                    else {
                        cout << "Cannot found the student or invalid data! Enter 1 to try it again, or other numbers to go back to the menu.\n";
                        int tryagain;
                        cin >> tryagain;
                        if (tryagain == 1) {
                            continue;
                        }
                        else break;
                    }
                }  
                break;
            }
            case 5: {
                FileIO::writeStudentsToFile("data.txt", students);
                break;
            }
            case 0: {
                running = false;
                break;
            }
            default:{
                cout << "Please enter a valid num!\n";
                break;
            }
        }
    }
    cout << "Bye!\n";
    return 0;
}