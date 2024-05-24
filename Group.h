#pragma once
#include <iostream>
#include "SchoolManagementSystem.h"
#include"Section.h"
#include "Schedule.h"
class School;
class Section;
class Schedule;
class Student;
class Administrator;
template <class V> V*getObject(long);
bool ObjectNew(long,string);
long GetNewID(string);

class Group {
    long ObjectID;
    int groupNumber;
    Section *section;
    Schedule *timetable;
    std::vector<Student *> students;
public:
    long getObjectID() const { return ObjectID; }
    void setObject(long)
    {
        if (ObjectNew(ObjectID,"Group"))
        {
            this->ObjectID = ObjectID;
        }
        else
            ObjectID = 0;
    };
    Group(int gnum=0, Section *sec=nullptr, Schedule *tt=nullptr);
    void addStudent(Student *student);
    void setSection(Section* Sec=nullptr);
    Section * getSection() const;   
    Schedule * getTimeTable() const;
    void setTimetable(Schedule *tt=nullptr);
    int getGroupNumber() const;
    void setGroupNumber(int gnum);
    friend std::ostream &operator<<(std::ostream &os, const Group &Group);
    friend std::istream &operator>>(std::istream &is, Group &Group);
};

