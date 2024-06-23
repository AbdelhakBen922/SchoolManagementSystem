/*
 * Session.h
 *
 *  Created on: Jun 13, 2024
 *      Author: kali9
 */

#ifndef SESSION_H_
#define SESSION_H_


#include <iostream>
#include <string>
#include "Time.h"
#include "Date.h"
#include "Schedule.h"
#include "funcs.h"

class Session
{

    long ObjectID;
    long course;
    long timetable;
    long time;


public:
    long getObjectID() const { return ObjectID; }
    void setObject(long);
    Session(long =-1,long =-1);

    long getCourse() const;
    long getTime() const;
    long getTutor() const;
    long getTimetable() const;
    long getPlace() const;

    void setCourse(long newCourse);
    void setTime(long newTime);
    void setTimetable(long newTimetable);
    friend std::ostream &operator<<(std::ostream &os, const Session &Session);
    friend std::istream &operator>>(std::istream &is, Session &Session);
};

#endif /* SESSION_H_ */
