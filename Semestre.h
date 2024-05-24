#pragma once
#include <iostream>
#include "Course.h"
#include "Year.h"
#include "SchoolManagementSystem.h"
class Course;
class Year;

class Semestre {
    long ObjectID;
public:
    long getObjectID() const { return ObjectID; }
    void setObject(long)
    {
        if (ObjectNew(ObjectID,"Semestre"))
        {
            this->ObjectID = ObjectID;
        }
        else
            ObjectID = 0;
    }

private:
    int semesterNumber;
    Year *year;
    std::vector<Course *> courses;

public:
    Semestre(Year *y=nullptr, int sn=0);
    void setCourses(const std::vector<Course *> &courses);
    int getSemesterNumber() const;
    void setSemesterNumber(int sn);
    friend std::ostream &operator<<(std::ostream &os, const Semestre &Semestre);
    friend std::istream &operator>>(std::istream &is, Semestre &Semestre);
};

