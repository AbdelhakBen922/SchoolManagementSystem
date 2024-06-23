/*
 * Student.cpp
 *
 *  Created on: Jun 13, 2024
 *      Author: kali9
 */

#include "Student.h"
#include "Semestre.h"

using std::ostream;
using std::istream;

Student::Student(std::string firstName, std::string familyName, std::string email, std::string phone, std::string Photo, int age, long schoolId, long g, long s): Profile(firstName, familyName, email, phone, Photo, age, schoolId), group(g),semestre(s)

{
	ObjectID=GetNewID("Student");
    absences = std::vector<long>();
    Semestre S= GetObject<Semestre>(semestre);
    std::vector<long> Courses=S.getCourses();
    for (auto &course :Courses){
    	courses.push_back(SCourse {course});
    }
}

Session Student::getSession(Time *t)
{
    if (!t)return Session {};
    saveToFile<Time>(*t);
    Clean("Times.txt");
    Group g = GetObject<Group>(group); // @suppress("Invalid arguments")
    long s=g.getTimeTable();

    return Session {s,t->getObjectID()};
}
ostream& operator<<(ostream &out, const Student &student)
{
    out << static_cast<const Profile &>(student)<<"\n";
    out << student.group << "\n";
    out << student.semestre << "\n";
    for (auto &absence : student.absences)
    {
        out << absence << "\n";
    }
    for (auto &course : student.courses)
    {
        out << course << "\n";
    }
    return out;
}
istream& operator>>(istream& is ,Student & student){
    is >> static_cast<Profile &>(student);
    long id;

    is>>student.group;
    is >> student.semestre;
    while(is>>id){
        student.absences.push_back(id);
    }
    SCourse i;
    while (is>>i){
        student.courses.push_back(i);
    }
    return is;
}
long Student::getSemestre()const{return semestre;}
long Student::getGroup()const{return group;}
std::vector<SCourse*> Student::getCourses()const{
    std::vector<SCourse*> temp;
    for (auto scourse:courses){
        temp.push_back(&scourse);
    }
    return temp;
}

