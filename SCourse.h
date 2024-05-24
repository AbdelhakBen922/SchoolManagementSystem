#pragma once
#include <iostream>
#include <vector>
#include "Course.h"
class Course;
#include "Exam.h"
class Exam;
class SCourse{
private:
    long ObjectID;
    Course* course;
    Exam midterm;
    Exam final;
    std::vector<Exam > tests;

public:
    SCourse(Course* course=nullptr);
    long getObjectID() const { return ObjectID; }
    void setObject(long)
    {
        if (ObjectNew(ObjectID ,"Schedule"))
        {
            this->ObjectID = ObjectID;
        }
        else
            ObjectID = 0;
    };

    friend std::ostream &operator<<(std::ostream &os, const SCourse &SCourse);
    friend std::istream &operator>>(std::istream &is, SCourse &SCourse);
};


