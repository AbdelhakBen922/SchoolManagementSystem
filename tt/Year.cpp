/*
 * Year.cpp
 *
 *  Created on: Jun 13, 2024
 *      Author: kali9
 */

#include "Year.h"
Year::Year(int y) {
    setObject(GetNewID("Year"));
    setYearNumber(y);
    sections = vector<long> {};
}

void Year::setSections(const std::vector<long> &sections)
{
    this->sections = sections;
}
vector<long> &Year::getSections()
{
    return sections;
}
int Year::getYearNumber() const
{
    return yearNumber;
}

void Year::setYearNumber(int y)
{
    yearNumber = y;
}
std::ostream &operator<<(std::ostream &os, const Year &year)
{
    os << year.ObjectID<<std::endl;
    os << year.yearNumber<<std::endl;
    for (auto &section : year.sections)
    {
        os << section<<std::endl;
    }
    return os;
}
std::istream &operator>>(std::istream &is, Year &year)
{
	std::string ignore;
	std::getline(is,ignore);
    is >> year.ObjectID;
    int yearNumber;
    is >> yearNumber;
    year.setYearNumber(yearNumber);
    long sectionID;
    while (is >> sectionID)
    {
        year.sections.push_back(sectionID);
    }
    return is;
}
void Year::setObject(long ObjectID)
{
    if (ObjectNew(ObjectID,"Place"))
    {
        this->ObjectID = ObjectID;
    }
    else
        ObjectID = 0;
}

