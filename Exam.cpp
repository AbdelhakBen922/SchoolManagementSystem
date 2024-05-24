#include "Exam.h"
#include <iostream>
#include "SchoolManagementSystem.h"

Exam::Exam(Time* t, Course* c, float m, int mm)
{
    ObjectID = GetNewID("Exam");
    setTime(t);
    setCourse(c);
    setMark(m);
    setMaxMark(mm);

}




Time *Exam::getTime() const
{
    return time;
}

void Exam::setTime(Time *t)
{
    time = t;
}

Course *Exam::getCourse() const
{
    return course;
}

void Exam::setCourse(Course *c)
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
    os << Exam.course->getObjectID()<<std::endl;
    os << Exam.time->getObjectID()<<std::endl;
    os << Exam.mark<<std::endl;
    os << Exam.maxMark<<std::endl;
    return os;
}
std::istream& operator>>(std::istream& is , Exam& Exam){
    is >> Exam.ObjectID;
    long id;
    is >> id;
    Exam.course = getObject<Course>(id);
    is >> id;
    Exam.time = getObject<Time>(id);
    is >> Exam.mark;
    is >> Exam.maxMark;
    return is;

}
