
#include "Student.h"
#include "Profile.h"
#include "Time.h"
#include "Year.h"
#include "Group.h"
#include "SCourse.h"
#include "Session.h"
#include <iostream>
#include "SchoolManagementSystem.h"
#include "School.h"
#include "func.h"
using std::ostream;
using std::istream;

Student::Student(std::string firstName, std::string familyName, std::string email, std::string phone, std::string Photo, int age, long schoolId, Year *y, Group *g): Profile(firstName, familyName, email, phone, Photo, age, schoolId), year(y), group(g)
{
    absences = std::vector<Time *>();
    courses = std::vector<SCourse >();
}

Session Student::getSession()
{
    Time t = getcurrentTime();
   
    return Session {group->getTimeTable(),GetPointers<Time>(t,getSchool())};
}
ostream& operator<<(ostream &out, const Student &student)
{
    out << static_cast<const Profile &>(student)<<"\n";
    out << student.year->getObjectID() << "\n";
    out << student.group->getObjectID() << "\n";
    for (auto &absence : student.absences)
    {
        out << absence->getObjectID() << "\n";
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
    is >> id;
    student.year = getObject<Year>(id);
    student.group = getObject<Group>(id);
    while(is>>id){
        student.absences.push_back(getObject<Time>(id));
    }
    SCourse i;
    while (is>>i){
        student.courses.push_back(i);
    }
    return is;
}