/*
 * Semestre.cpp
 *
 *  Created on: Jun 13, 2024
 *      Author: kali9
 */

#include "Semestre.h"


Semestre::Semestre(long y, int sn) : year(y), semesterNumber(sn) {
	ObjectID=GetNewID("Semestre");
};
std::vector<long> & Semestre::getCourses(){return courses;}
void Semestre::setCourses(const std::vector<long> &c)
{
    courses = c;
}

int Semestre::getSemesterNumber() const
{
    return semesterNumber;
}

void Semestre::setSemesterNumber(int sn)
{
    semesterNumber = sn;
}
std::ostream &operator<<(std::ostream &os, const Semestre &semestre)
{
    os << semestre.ObjectID << "\n";
    os << semestre.semesterNumber << "\n";
    os << semestre.year << "\n";
    for (auto &course : semestre.courses)
    {
        os << course << "\n";
    }
    return os;
}

std::istream &operator>>(std::istream &is, Semestre &semestre)
{
	std::string ignore;
	std::getline(is,ignore);
    is >> semestre.ObjectID;
    is >> semestre.semesterNumber;
    long id;
    is >>  semestre.year;
    while (is >> id)
    {
        semestre.courses.push_back(id);
    }
    return is;
}
void Semestre::setObject(long ObjectID)
{
    if (ObjectNew(ObjectID,"Place"))
    {
        this->ObjectID = ObjectID;
    }
    else
        ObjectID = 0;
}
