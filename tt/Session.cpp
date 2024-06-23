/*
 * Session.cpp
 *
 *  Created on: Jun 13, 2024
 *      Author: kali9
 */

#include "Session.h"


Session::Session(long sch, long t):timetable(sch),time(t)  {
    ObjectID= GetNewID("Session");
    Time T=GetObject<Time>(time);
    long d = T.getDate();
    Date date = GetObject<Date>(d);
    int day =date.getDayOfWeek();
    int hour = T.getSessionNumber();
    Schedule s = GetObject<Schedule>(timetable);
    course = s.getCourse(day, hour - 1);
    }
// Getters

long Session::getCourse() const
{
    return course;
}

long Session::getTime() const
{
    return time;
}

long Session::getTutor() const
{
    Schedule s = GetObject<Schedule>(timetable);
    Time t=GetObject<Time>(time);
    long d = t.getDate();
	Date date = GetObject<Date>(d);
	int day =date.getDayOfWeek();
	int hour = t.getSessionNumber();
    return s.getTeacher(day,hour);
}

long Session::getTimetable() const
{
    return timetable;
}

long Session::getPlace() const
{
    Schedule s = GetObject<Schedule>(timetable);
    Time t=GetObject<Time>(time);
    long d = t.getDate();
	Date date = GetObject<Date>(d);
	int day =date.getDayOfWeek();
	int hour = t.getSessionNumber();
    return s.getPlace(day,hour);
}
// Setters
void Session::setCourse(long newCourse)
{
    course = newCourse;
}

void Session::setTime(long newTime)
{
    time = newTime;
}

void Session::setTimetable( long newTimetable)
{
    timetable = newTimetable;
}

std::ostream &operator<<(std::ostream &os, const Session &Session)
{
    os << Session.ObjectID << std::endl;
    os << Session.course << std::endl;
    os << Session.time << std::endl;
    os << Session.timetable << std::endl;
    return os;
}
std::istream &operator>>(std::istream &is, Session &Session)
{
	string ignore;
	std::getline(is,ignore);
    is >> Session.ObjectID;
    is >>Session.course;
    is >> Session.time;
    is >> Session.timetable;
    return is;
}
void Session::setObject(long ObjectID){

	if (ObjectNew(ObjectID, "Session"))
	{
		this->ObjectID = ObjectID;
	}
	else
		ObjectID = 0;

}
