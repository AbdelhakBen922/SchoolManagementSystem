#pragma once
#include <iostream>
#include "SchoolManagementSystem.h"
#include "Time.h"
#include "Course.h"
template <class V> V*getObject(long);
bool ObjectNew(long,string);
long GetNewID(string);
class Course;
class Time;
class Exam {
    long ObjectID;
     Time *time;
    Course *course;
    float mark;
    int maxMark;
public:
    long getObjectID() const { return ObjectID; }
    void setObject(long)
    {
        if (ObjectNew(ObjectID,"Exam"))
        {
            this->ObjectID = ObjectID;
        }
        else
            ObjectID = 0;
    };
    Exam(Time *t = nullptr, Course *c = nullptr, float m = 0, int mm = 0);
    Time *getTime() const;
    void setTime(Time *t);
    Course *getCourse() const;
    void setCourse(Course *c);
    float getMark() const;
    void setMark(float m);
    int getMaxMark() const;
    void setMaxMark(int mm);
    friend std::ostream &operator<<(std::ostream &os, const Exam &Exam);
    friend std::istream &operator>>(std::istream &is, Exam &Exam);
};




