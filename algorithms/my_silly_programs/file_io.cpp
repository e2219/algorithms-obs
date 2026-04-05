#include "file_io.h"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <string>
//读取：

//打开文件
//按行读取每个学生的数据
//拆分字段（姓名、学号、课程、成绩、学分）
//构造 Score 对象放入 Student 的 vector<Score>
//把每个 Student 放到 vector<Student>

using std::ifstream;
using std::ofstream;

std::vector<Student> FileIO::readStudentFromFile(const std::string filename) {
    vector<Student> students;
    ifstream fin(filename);
    string line;
    if (!fin.is_open()) {
        std::cout << "文件打开失败，请检查文件名或路径是否正确:" << filename << std::endl;
        return {};
    }
    while (std::getline(fin, line)) {
        if (line.empty()) continue;
        std::istringstream iss(line);
        string idstr, name;  
        if (!std::getline(iss, idstr, ',') || !std::getline(iss, name, ',')) {
            std::cerr << "行格式错误，跳过\n";
            continue;
        }
        Student student(std::stoi(idstr), name);
        while (!iss.eof()) {
            string courseStr;
            string gradeStr, creditStr, weightStr;
            if (!std::getline(iss, courseStr, ',')) break;
            if (!std::getline(iss, gradeStr, ',')) break;
            if (!std::getline(iss, creditStr, ',')) break;
            if (!std::getline(iss, weightStr, ',')) break;

            double grade = std::stod(gradeStr);
            double credit = std::stod(creditStr);
            double weight = std::stod(weightStr);

            Score score(courseStr, grade, credit, weight);
            student.addScore(score);
        }
        students.push_back(student);
   }
   return students;
}
void FileIO::writeStudentsToFile(const std::string& filename, const std::vector<Student> & students) {
    std::ofstream fout(filename);
    if (!fout.is_open()) {
        std::cout << "文件打开失败： " << filename << std::endl;
        return;
    }
    for (const auto & student : students) {
        fout << student.get_Id();
        fout << ",";
        fout << student.get_Name();
        for (const auto & score : student.get_Scores()) {
            fout << ",";
            fout << score.getCourseName() << "," << score.getGrade() << ",";
            fout << score.getCredit() << "," << score.getWeight();
        }
        fout << "\n";
    }
}