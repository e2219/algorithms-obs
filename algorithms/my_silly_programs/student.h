#pragma once

//1. 添加学生
//2. 删除学生
//3. 修改成绩
//4. 显示所有学生
//5. 按平均分排序
//0. 退出

#include <string>
#include <vector>
#include "Score.h"

using std::string; 
using std::vector;

class Student {

private:
    int id;
    string name;
    vector<Score> scores;

public:
    Student(const int Studentid = 0, const string &Studentname = "小明")
        :id(Studentid),
         name(Studentname){}
    ~Student() = default;
    string get_Name() const;
    int get_Id() const;
    void addScore(const Score & score);
    const vector<Score>& get_Scores() const;
    double calculateGPA();
    void printScores() const;
};