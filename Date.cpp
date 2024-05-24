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
    is >> date.day >> date.month >> date.year >> date.dayOfWeek;
    return is;
}
