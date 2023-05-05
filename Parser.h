#ifndef STUDENTS_1S_PARSER_H
#define STUDENTS_1S_PARSER_H

#include <string>
#include <vector>

#include "Subject.h"


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





#endif //STUDENTS_1S_PARSER_H
