/*
 * Date.h
 *
 *  Created on: Jun 12, 2024
 *      Author: kali9
 */

#ifndef DATE_H_
#define DATE_H_

#include <iostream>
#include "funcs.h"
using std::string;
class Date {

    long ObjectID;

public:
    long getObjectID() const { return ObjectID; }
    void setObject(long id );

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
    Date operator+(int);
    friend std::ostream &operator<<(std::ostream &os, const Date &date);
    friend std::istream &operator>>(std::istream &is, Date &date);
};

#endif /* DATE_H_ */
