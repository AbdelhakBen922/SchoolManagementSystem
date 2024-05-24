#pragma once
#include <iostream>
#include "Course.h"
#include "Time.h"
#include "Date.h"
#include "Schedule.h"
#include "Place.h"
#include "SchoolManagementSystem.h"

class Session
{

    long ObjectID;

public:
    long getObjectID() const { return ObjectID; }
    void setObject(long)
    {
        if (ObjectNew(ObjectID, "Session"))
        {
            this->ObjectID = ObjectID;
        }
        else
            ObjectID = 0;
    }

private:
    Course *course;
    Time *time;
    Teacher *tutor;
    Schedule *timetable;
    Place *place;

public:
    Session(Schedule *timetable=nullptr, Time *time=nullptr);

    Course *getCourse() const;
    Time *getTime() const;
    Teacher *getTutor() const;
    Schedule *getTimetable() const;
    Place *getPlace() const;

    void setCourse(Course *newCourse);
    void setTime(Time *newTime);
    void setTutor(Teacher *newTutor);
    void setTimetable(Schedule *newTimetable);
    void setPlace(Place *newPlace);
    friend std::ostream &operator<<(std::ostream &os, const Session &Session);
    friend std::istream &operator>>(std::istream &is, Session &Session);
};
