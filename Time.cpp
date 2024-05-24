#include "Time.h"
#include <ctime>

Time::Time(Date *d, int session)
    : date(d)
{
    setSessionNumber(session);
}

Time::Time(const time_t &time)
{
    struct tm* t = localtime(&time); // Convert time_t to struct tm
    date = new Date(t->tm_mday, t->tm_mon, t->tm_year, t->tm_wday);
    setSessionNumber(t->tm_hour);
}
void Time::setDate(Date *d)
{
   date = d;
}
Date *Time::getDate() const
{
    return date;
}
int Time::getSessionNumber() const
{
    return sessionNumber;
}
void Time::setSessionNumber(int session)
{
    if (session >= 0 && session <= 6)
        sessionNumber = session;
    else
        sessionNumber = 0;
}
std::ostream &operator<<(std::ostream &os, const Time &time)
{
    os << time.ObjectID<<std::endl;
    os << time.sessionNumber<<std::endl;
    os << time.date->getObjectID()<<std::endl;
    return os;
}
std::istream &operator>>(std::istream &is, Time &time)
{
    long ObjectID;
    is >> ObjectID;
    time.setObject(ObjectID);
    int sessionNumber;
    is >> sessionNumber;
    time.setSessionNumber(sessionNumber);
    long dateID;
    is >> dateID;
    time.date= getObject<Date>(dateID);
    return is;
}