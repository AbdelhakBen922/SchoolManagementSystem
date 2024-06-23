/*
 * Date.cpp
 *
 *  Created on: Jun 12, 2024
 *      Author: kali9
 */

#include "Date.h"


Date::Date(int d, int m, int y, int dow)
{
    ObjectID = GetNewID("Date");
    setDay(d);
    setMonth(m);
    setYear(y);
    setDayOfWeek(dow);
}
int Date::getDay() const
{
    return day;
}

void Date::setDay(int d)
{
    if (month == 2)
    {
        bool isLeapYear(int);
        if(isLeapYear(year)){
            if (d > 0 && d < 30)
            {
                day = d;
            }
            else
            {
                day = 0;
            }
        }
        else{
            if (d > 0 && d < 29)
            {
                day = d;
            }
            else
            {
                day = 0;
            }
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (d > 0 && d < 31)
        {
            day = d;
        }
        else
        {
            day = 0;
        }
    }
    else
    {
        if (d > 0 && d < 32)
        {
            day = d;
        }
        else
        {
            day = 0;
        }
    }

}

int Date::getMonth() const
{
    return month;
}

void Date::setMonth(int m)
{
    if(m>0 && m<13){
        month = m;
    }
    else{
        month = 0;

}}

int Date::getYear() const
{
    return year;
}

void Date::setYear(int y)
{
    year = y;
}

int Date::getDayOfWeek() const
{
    return dayOfWeek;
}

void Date::setDayOfWeek(int dow)
{
    dayOfWeek = dow;
}
std::ostream &operator<<(std::ostream &os, const Date &date)
{
    os << date.day << " " << date.month << " " << date.year << " " << date.dayOfWeek;
    return os;
}

// Overload the input operator
std::istream &operator>>(std::istream &is, Date &date)
{
	std::string ignore;
		is >> ignore;
    is >> date.day >> date.month >> date.year >> date.dayOfWeek;
    return is;
}

void Date::setObject(long ObjectID)
{
    if (ObjectNew(ObjectID,"Place"))
    {
        this->ObjectID = ObjectID;
    }
    else
        ObjectID = 0;
}
Date Date::operator+(int d){
    if (d<=0)return *this;
    Date NextDate=*this;
    NextDate.setDay(day+d);
    if (NextDate.getDay()==0){
        NextDate.setMonth(month+1);
        if (NextDate.getMonth()==0){
            setYear(year+1);
        }
    }
    NextDate.setDayOfWeek(GetDayOfWeek(NextDate.getDay(),NextDate.getMonth(),NextDate.getYear()));
    return NextDate;
}
