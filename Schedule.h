#pragma once
#include <iostream>
#include <vector>
#include "Course.h"
#include "Place.h"
#include "School.h"
#include "SchoolManagementSystem.h"

class School;
class Teacher;
class Course;
class Teacher;
class Place;

using std::vector;
using std::string;
bool ObjectNew(long,string);
long GetNewID(string);
template <class V> V*getObject(long);


class Schedule {
    long ObjectID;
    Course *timeTable[5][6];
    Teacher *tutors[5][6];
    Place *places[5][6];
public:
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

    Schedule();
    Schedule(Course *tt[5][6], Teacher *t[5][6], Place *p[5][6]);
    void setCourses(Course *tt[5][6]);
    void setTutors(Teacher *t[5][6]);
    void setPlaces(Place *p[5][6]);
    Course *getCourse(int = 0, int = 0) const;
    Teacher *getTeacher(int = 0, int = 0) const;
    Place *getPlace(int = 0, int = 0) const;
    template <class V>
    friend vector<V *> GetPointers(School*);
    template <class V>
    friend V *GetPointers(int,School*);
    template <class V>
    friend V *GetPointers(V&,School*);
    friend std::ostream &operator<<(std::ostream &os, const Schedule &Schedule);
    friend std::istream &operator>>(std::istream &is, Schedule &Schedule);
};


