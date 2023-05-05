#ifndef STUDENTS_1S_STUDENT_H
#define STUDENTS_1S_STUDENT_H

#include <string>
#include <vector>

#include "Subject.h"

using namespace std;

struct Student{
int id;
string first_name;
string last_name;
vector<Subject> subjects;
};


#endif //STUDENTS_1S_STUDENT_H
