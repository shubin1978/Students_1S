#ifndef STUDENTS_1S_STUDENTSDB_H
#define STUDENTS_1S_STUDENTSDB_H

#include <map>
#include <fstream>

#include "Student.h"
#include "Parser.h"

struct StudentsDB{

    const string PATH = "students.db";
    int id;

   map<int,Student> students;

   // CRUD
    // *Create
    // *Read
    // *Update
    // *Delete

   void Add(Student student){
       id += 1;
       student.id = id;
       students.insert(pair<int,Student>(id, student));
       Export();
   }

   void Update(int id){
       // TODO
   };

   void Delete(int id){
       // TODO
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

           auto student = ParserStudent(line);
           students.insert(pair<int, Student> (student.id,student));
       }
       id = students.end()->second.id;
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

   vector<Student> ToVector(){
       vector<Student> result;
       for (auto student : students) {
           result.push_back(student.second);
       }
       return result;
   }

};



#endif //STUDENTS_1S_STUDENTSDB_H
