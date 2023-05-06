#ifndef STUDENTS_1S_PARSER_H
#define STUDENTS_1S_PARSER_H

#include <string>
#include <vector>

#include "Subject.h"
#include "Student.h"


using namespace std;

const char GENERAL_DELIMITER = '|';
const char SUBJECT_DELIMITER = ';';
const char SUBJECT_NAME_DELIMITER = ':';
const char MARK_DELIMITER = ',';


string Parser(string& str, char delemeter){
    int pos = str.find(delemeter);
    string result = str.substr(0,pos);
    str = str.substr(pos + 1);
    return result;
}

vector <int> ParserMarks(string marks_str){
    vector<int> marks;
    do {
        marks.push_back(stoi(Parser(marks_str,MARK_DELIMITER)));
    } while (marks_str != "");
    return marks;
}

vector<Subject> ParserSubjects(string subjects_str){
    vector<Subject> subjects;
    do{
        Subject subject;
        string subject_str = Parser(subjects_str,SUBJECT_DELIMITER);
        subject.name = Parser(subject_str,SUBJECT_NAME_DELIMITER);
        subject.marks = ParserMarks(subject_str);
        subjects.push_back(subject);
    } while (subjects_str != "");

    return subjects;
}

Student ParserStudent(string student_str){
   Student student;
    student.id = stoi(Parser(student_str,GENERAL_DELIMITER));
    student.last_name = Parser(student_str,GENERAL_DELIMITER);
    student.first_name = Parser(student_str,GENERAL_DELIMITER);
    student.subjects = ParserSubjects(student_str);
    return student;
}

#endif //STUDENTS_1S_PARSER_H
