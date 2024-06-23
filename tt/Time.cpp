/*
 * Time.cpp
 *
 *  Created on: Jun 12, 2024
 *      Author: kali9
 */


#include "Time.h"
#include "Date.h"

Time getcurrentTime()
{
    std::time_t t;
	t=(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    Time Ct(&t); // @suppress("Ambiguous problem")
    return Ct;
}

Time::Time( std::time_t* T)
{
	time_t time=*T;
	ObjectID=GetNewID("Time");
    struct tm* t = localtime(&time); // Convert time_t to struct tm
    Date *d= new Date(t->tm_mday, t->tm_mon, t->tm_year, t->tm_wday);
    date=d->getObjectID();
    setSessionNumber(t->tm_hour);
}
void Time::setDate(long d)
{
   date = d;
}
long Time::getDate() const
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
    os << time.date<<std::endl;
    return os;
}
std::istream &operator>>(std::istream &is, Time &time)
{
	std::string ignore;
	is >> ignore;
    long ObjectID;
    is >> ObjectID;
    time.setObject(ObjectID);
    int sessionNumber;
    is >> sessionNumber;
    time.setSessionNumber(sessionNumber);
    is >> time.date;
    return is;
}
void Time::setObject(long ObjectID)
{
    if (ObjectNew(ObjectID,"Place"))
    {
        this->ObjectID = ObjectID;
    }
    else
        ObjectID = 0;
}
Time::Time(long d, int session)
    : date(d)
{
	ObjectID=GetNewID("Time");
    setSessionNumber(session);
}
Time::~Time(){
};
Time Time::operator+(int h){
    Time NextTime =*this;
    NextTime.setSessionNumber(sessionNumber+h);
    if (NextTime.getSessionNumber()==0){
        Date NextDate=date+(h/7);
        saveToFile(NextDate);
        Clean("Dates.txt");
        NextTime.setDate(NextDate.getObjectID());
    }
    return NextTime;
}
