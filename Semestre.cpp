#include "Semestre.h"

Semestre::Semestre(Year *y, int sn) : year(y), semesterNumber(sn) {}

void Semestre::setCourses(const std::vector<Course *> &c)
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
    os << semestre.year->getObjectID() << "\n";
    for (auto &course : semestre.courses)
    {
        os << course->getObjectID() << "\n";
    }
    return os;
}

std::istream &operator>>(std::istream &is, Semestre &semestre)
{
    is >> semestre.ObjectID;
    is >> semestre.semesterNumber;
    long id;
    is >> id;
    semestre.year = getObject<Year>(id);
    while (is >> id)
    {
        semestre.courses.push_back(getObject<Course>(id));
    }
    return is;
}
