#include "Session.h"
#include "Teacher.h"


Session::Session(Schedule *sch, Time *t):timetable(sch),time(t)  {
    ObjectID= GetNewID("Session");
    int day = t->getDate()->getDayOfWeek();
    int hour = t->getSessionNumber();
    course = sch->getCourse(day, hour - 1);
    tutor = sch->getTeacher(day, hour - 1);
    place = sch->getPlace(day, hour - 1);
    }
// Getters

Course *Session::getCourse() const
{
    return course;
}

Time *Session::getTime() const
{
    return time;
}

Teacher *Session::getTutor() const
{
    return tutor;
}

Schedule *Session::getTimetable() const
{
    return timetable;
}

Place *Session::getPlace() const
{
    return place;
}
// Setters
void Session::setCourse(Course *newCourse)
{
    course = newCourse;
}

void Session::setTime(Time *newTime)
{
    time = newTime;
}

void Session::setTutor(Teacher *newTutor)
{
    tutor = newTutor;
}

void Session::setTimetable(Schedule *newTimetable)
{
    timetable = newTimetable;
}
void Session::setPlace(Place *newPlace)
{
    place = newPlace;
}
std::ostream &operator<<(std::ostream &os, const Session &Session)
{
    os << Session.ObjectID << std::endl;
    os << Session.course->getObjectID() << std::endl;
    os << Session.time->getObjectID() << std::endl;
    os << Session.tutor->getObjectID() << std::endl;
    os << Session.timetable->getObjectID() << std::endl;
    return os;
}
std::istream &operator>>(std::istream &is, Session &Session)
{
    is >> Session.ObjectID;
    long courseID;
    long timeID;
    long tutorID;
    long timetableID;
    is >> courseID;
    is >> timeID;
    is >> tutorID;
    is >> timetableID;
    Session.course = getObject<Course>(courseID);
    Session.time = getObject<Time>(timeID);
    Session.tutor = getObject<Teacher>(tutorID);
    Session.timetable = getObject<Schedule>(timetableID);
    return is;
}