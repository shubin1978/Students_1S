#ifndef STUDENTS_1S_STUDENTSDB_H
#define STUDENTS_1S_STUDENTSDB_H

#include <map>
#include <fstream>

#include "Student.h"
#include "Parser.h"

struct StudentsDB{
    const char GENERAL_DELIMITER = '|';
    const char SUBJECT_DELIMITER = ';';
    const char SUBJECT_NAME_DELIMITER = ':';
    const char MARK_DELIMITER = ',';

    const string PATH = "students.db";
    int id;

   map<int,Student> students;

   void Add(Student student){
       id += 1;
       student.id = id;
       students.insert(pair<int,Student>(id, student));
       Export();
   }

   void Update(int id){

   };

   void Init(){
       ifstream file;
       file.open(PATH);

       if (!file.is_open()){
           id = 0;
           return;
       }

       string  line;
       while(getline(file,line)){
           if (line == ""){
               id = 0;
               return;
           }

           // line = "0|Ivanov|Anton|History:3,4,3,;Math:4,5,";
           int id_ = stoi(Parser(line,GENERAL_DELIMITER));
           //id_ = 0;
           //line = "Ivanov|Anton|History:3,4,3,;Math:4,5,";

           string last_name_ = Parser(line,GENERAL_DELIMITER);
           //last_name_ = "Ivanov";
           //line = "Anton|History:3,4,3,;Math:4,5,";

           string first_name_ = Parser(line,GENERAL_DELIMITER);
           //first_name_ = "Anton";
           //line = "History:3,4,3,;Math:4,5,";


           string subjects_ = line;
           //subjects_ = "History:3,4,3,;Math:4,5,";

           do{
               string subject_ = Parser(subjects_,SUBJECT_DELIMITER);
                // subject_ = "History:3,4,3,";
               //  subjects_ = "Math:4,5,";

               string subject_name_ = Parser(subject_,SUBJECT_NAME_DELIMITER);
               // subject_name = History";
               // subject_ = "3,4,3,";

               string marks_ = subject_;
               // marks = "3,4,3,";
               do {
                   int mark_ = stoi(Parser(marks_,MARK_DELIMITER));
                   //mark_ = 3,
                   //marks_ = "4,3,";

               } while (marks_ != "");


           } while (subjects_ != "");

       }
   };

   void Export(){
       ofstream file;
       file.open(PATH,ios::trunc);
       for (auto s : students) {
           auto student = s.second;
           file << student.id << "|" << student.last_name << "|" << student.first_name << "|";
           for (Subject subject : student.subjects) {
               file << subject.name << ":" ;
               for (int mark : subject.marks) {
                   file << mark << ",";
               }
               file << ";";
           }
           file << endl;
       }

       file.close();
   }

};



#endif //STUDENTS_1S_STUDENTSDB_H
