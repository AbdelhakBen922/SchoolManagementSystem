#pragma once
#include <iostream>

#include "SchoolManagementSystem.h"
using std::string;
template <class V> V*getObject(long);

bool ObjectNew(long,string);
class Date {

    long ObjectID;

public:
    long getObjectID() const { return ObjectID; }
    void setObject(long)
    {
        if (ObjectNew(ObjectID,"Date"))
        {
            this->ObjectID = ObjectID;
        }
        else
            ObjectID = 0;
    }

private:
    int day;
    int month;
    int year;
    int dayOfWeek;

public:
    Date(int day = 0, int month = 0, int year = 0, int dow = 0);
    int getDay() const;
    void setDay(int d);
    int getMonth() const;
    void setMonth(int m);
    int getYear() const;
    void setYear(int y);
    int getDayOfWeek() const;
    void setDayOfWeek(int dow);
    friend std::ostream &operator<<(std::ostream &os, const Date &date);
    friend std::istream &operator>>(std::istream &is, Date &date);
};



