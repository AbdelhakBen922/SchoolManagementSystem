/*
 * Exam.cpp
 *
 *  Created on: Jun 13, 2024
 *      Author: kali9
 */

#include "Exam.h"


Exam::Exam(long t, long c, float m, int mm)
{
    ObjectID = GetNewID("Exam");
    setTime(t);
    setCourse(c);
    setMark(m);
    setMaxMark(mm);

}




long Exam::getTime() const
{
    return time;
}

void Exam::setTime(long t)
{
    time = t;
}

long Exam::getCourse() const
{
    return course;
}

void Exam::setCourse(long c)
{
    course = c;
}

float Exam::getMark() const
{
    return mark;
}

void Exam::setMark(float m)
{
    if(m >= 0 && m <= maxMark)
    {
        mark = m;
    }
    else
    {
        mark = 0;
    }
}

int Exam::getMaxMark() const
{
    return maxMark;
}

void Exam::setMaxMark(int mm)
{
    maxMark = (mm > 0) ? mm : 0;
}

std::ostream& operator<<(std::ostream& os, const Exam& Exam)
{
    os << Exam.ObjectID<<std::endl;
    os << Exam.course<<std::endl;
    os << Exam.time<<std::endl;
    os << Exam.mark<<std::endl;
    os << Exam.maxMark<<std::endl;
    return os;
}
std::istream& operator>>(std::istream& is , Exam& Exam){
    std::string ignore;
    std::getline(is,ignore);
	is >> Exam.ObjectID;
    is >> Exam.course;
    is >> Exam.time;
    is >> Exam.mark;
    is >> Exam.maxMark;
    return is;

}
void Exam::setObject(long ObjectID)
    {
        if (ObjectNew(ObjectID ,"Schedule"))
        {
            this->ObjectID = ObjectID;
        }
        else
            ObjectID = 0;
    }

