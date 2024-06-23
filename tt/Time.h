/*
 * Time.h
 *
 *  Created on: Jun 12, 2024
 *      Author: kali9
 */

#ifndef TIME_H_
#define TIME_H_

#include <iostream>
#include "Date.h"
#include "funcs.h"
#include <ctime>
#include <chrono>


class Time {
    long ObjectID;
    long date;
    int sessionNumber;
public:
    long getObjectID() const { return ObjectID; };
    void setObject(long);

    Time(long=-1, int=-1);
    Time( std::time_t *);
    ~Time();
    long getDate() const;
    void setDate(long d);
    int getSessionNumber() const;
    void setSessionNumber(int session);
    Time operator+(int);
    friend std::ostream &operator<<(std::ostream &os, const Time &time);
    friend std::istream &operator>>(std::istream &is, Time &time);
};

Time getcurrentTime();


#endif /* TIME_H_ */
