/*
 * Place.cpp
 *
 *  Created on: Jun 12, 2024
 *      Author: kali9
 */

#include "Place.h"
#include "Time.h"
#include "Schedule.h"
Place::Place(const std::string &n)  {
    ObjectID=GetNewID("Place");
    setName(n);
}

const std::string &Place::getName() const
{
    return name;
}

void Place::setName(const std::string &n)
{
    name = n;
}
long Place::currentUse(long T) const
{
    int day;
    int hour;
    {
        Time T = getcurrentTime();
        day = GetObject<Date>(T.getDate()).getDayOfWeek();
        hour = T.getSessionNumber();
    }
    if (day >= 5 || hour > 7)
        return -1;
    return GetObject<Schedule>(T).getCourse(day, hour - 1);
}
std::ostream& operator<<(std::ostream &os, const Place &Place)
{
    os << Place.ObjectID << std::endl;
    os << Place.name<<std::endl;
    return os;
}
std::istream& operator>>(std::istream &is, Place &Place)
{
	std::string ignore;
	std::getline(is,ignore);
    std::getline(is,ignore);
    Place.ObjectID=std::stol(ignore);
    std::getline(is,Place.name);
    return is;
}

void Place::setObject(long ObjectID)
    {
        if (ObjectNew(ObjectID,"Place"))
        {
            this->ObjectID = ObjectID;
        }
        else
            ObjectID = 0;
    }

