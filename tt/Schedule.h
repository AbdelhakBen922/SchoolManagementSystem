/*
 * Schedule.h
 *
 *  Created on: Jun 12, 2024
 *      Author: kali9
 */

#ifndef SCHEDULE_H_
#define SCHEDULE_H_


#include <iostream>
#include <vector>
#include <string>
#include "funcs.h"



using std::vector;
using std::string;
bool ObjectNew(long,string);
long GetNewID(string);
template <class V> V*getObject(long);


class Schedule {
    long ObjectID;
    long timeTable[5][6];
    long tutors[5][6];
    long places[5][6];
public:
    long getObjectID() const { return ObjectID; }
    void setObject(long);

    Schedule();
    Schedule(long tt[5][6], long t[5][6], long p[5][6]);
    void setCourses(long tt[5][6]);
    void setTutors(long t[5][6]);
    void setPlaces(long p[5][6]);
    long getCourse(int = 0, int = 0) const;
    long getTeacher(int = 0, int = 0) const;
   long getPlace(int = 0, int = 0) const;
    friend std::ostream &operator<<(std::ostream &os, const Schedule &Schedule);
    friend std::istream &operator>>(std::istream &is, Schedule &Schedule);
};




#endif /* SCHEDULE_H_ */
