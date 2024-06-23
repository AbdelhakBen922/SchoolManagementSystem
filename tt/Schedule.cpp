/*
 * Schedule.cpp
 *
 *  Created on: Jun 12, 2024
 *      Author: kali9
 */

#include "Schedule.h"
#include "Teacher.h"
Schedule::Schedule()
{
    ObjectID=GetNewID("Schedule");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            timeTable[i][j] = -1;
            tutors[i][j] = -1;
            places[i][j] = -1;
        }
    }
}
Schedule::Schedule(long tt[5][6], long t[5][6], long p[5][6])
{
    ObjectID=GetNewID("Schedule");
    // Assuming simple direct assignment for illustrative purposes
    std::copy(&tt[0][0], &tt[0][0] + 5 * 6, &timeTable[0][0]);
    std::copy(&t[0][0], &t[0][0] + 5 * 6, &tutors[0][0]);
    std::copy(&p[0][0], &p[0][0] + 5 * 6, &places[0][0]);
}

void Schedule::setCourses(long tt[5][6])
{
    std::copy(&tt[0][0], &tt[0][0] + 5 * 6, &timeTable[0][0]);
}

void Schedule::setTutors(long t[5][6])
{
    std::copy(&t[0][0], &t[0][0] + 5 * 6, &tutors[0][0]);
}

void Schedule::setPlaces(long p[5][6])
{
    std::copy(&p[0][0], &p[0][0] + 5 * 6, &places[0][0]);
}
long Schedule::getCourse(int day, int hour) const
{
    if ((day < 0 || day >= 5) || (hour < 0 || hour >= 7))
        return -1;
    return timeTable[day][hour];
}
long Schedule::getTeacher(int day, int hour) const
{
    if ((day < 0 || day >= 5) || (hour < 0 || hour >= 7))
        return -1;
    return tutors[day][hour];
}
long Schedule::getPlace(int day, int hour) const
{
    if ((day < 0 || day >= 5) || (hour < 0 || hour >= 7))
        return -1;
    return places[day][hour];
}

std::ostream &operator<<(std::ostream &os, const Schedule &Schedule)
{
    os << Schedule.ObjectID << std::endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            os << Schedule.timeTable[i][j] << " ";
            os << Schedule.tutors[i][j] << " ";
            os << Schedule.places[i][j]<< " ";
        }
        os << std::endl;
    }
    return os;
}
std::istream &operator>>(std::istream &is, Schedule &Schedule)
{
	 std::string ignore;
	 std::getline(is,ignore);
    is >> Schedule.ObjectID;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            is >> Schedule.timeTable[i][j] >> Schedule.tutors[i][j] >> Schedule.places[i][j];
        }
    }
    return is;
}


void Schedule::setObject(long ObjectID)
{
    if (ObjectNew(ObjectID,"Place"))
    {
        this->ObjectID = ObjectID;
    }
    else
        ObjectID = 0;
}
