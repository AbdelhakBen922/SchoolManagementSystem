#pragma once
#include <iostream>
#include "Course.h"
#include "Schedule.h"
#include "SchoolManagementSystem.h"
class Schedule;
class Course;
using std::string;
using std::vector;
template <class V> V*getObject(long);

class Place {
    long ObjectID;
    std::string name;
public:
    long getObjectID() const { return ObjectID; }
    void setObject(long)
    {
        if (ObjectNew(ObjectID,"Place"))
        {
            this->ObjectID = ObjectID;
        }
        else
            ObjectID = 0;
    };
    explicit Place(const std::string &n = "");
    const std::string &getName() const;
    void setName(const std::string &name);
    Course *currentUse(Schedule *) const;
    friend std::ostream &operator<<(std::ostream &os, const Place &Place);
    friend std::istream &operator>>(std::istream &is, Place &Place);
};


