#pragma once

#include "Score.h"
#include "student.h"
#include <vector>
#include <string>



class FileIO {
public:
    static std::vector<Student> readStudentFromFile(const std::string filename);
    static void writeStudentsToFile(const std::string& filename, const std::vector<Student> & students);    
};