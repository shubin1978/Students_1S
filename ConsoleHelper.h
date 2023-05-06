#ifndef STUDENTS_1S_CONSOLEHELPER_H
#define STUDENTS_1S_CONSOLEHELPER_H

#include <iostream>
#include <vector>

#include "StudentsDB.h"

using namespace std;

void PrintStudent(Student student){
    cout << student.id << " : " << student.last_name << " " << student.first_name << endl;
    for (auto subject : student.subjects) {
        cout << "\t" << subject.name << " : ";
        for (auto  mark : subject.marks) {
            cout << mark << " ";
        }
        cout << endl;
    }
}

void PrintStudents(vector<Student> students){
    for (auto  student: students) {
        PrintStudent(student);
    }
}

#endif //STUDENTS_1S_CONSOLEHELPER_H
