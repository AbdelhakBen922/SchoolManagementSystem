#pragma once
#include <iostream>
#include "Date.h"

#include <ctime>
#include "SchoolManagementSystem.h"
using std::string;
bool ObjectNew(long,string);
class Date;
class Time {
    long ObjectID;
    Date *date;
    int sessionNumber;
public:
    long getObjectID() const { return ObjectID; }
    void setObject(long)
    {
        if (ObjectNew(ObjectID ,"Time"))
        {
            this->ObjectID = ObjectID;
        }
        else
            ObjectID = 0;
    };


    Time(Date *d = nullptr, int session = 0);
    explicit Time(const time_t &time);
    Date *getDate() const;
    void setDate(Date *d);
    int getSessionNumber() const;
    void setSessionNumber(int session);
    friend std::ostream &operator<<(std::ostream &os, const Time &time);
    friend std::istream &operator>>(std::istream &is, Time &time);
};



 