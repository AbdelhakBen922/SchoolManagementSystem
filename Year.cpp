#include "Year.h"
Year::Year(int y) {
    setObject(GetNewID("Year"));
    setYearNumber(y);
    sections = vector<Section*> {};
}

void Year::setSections(const std::vector<Section *> &sections)
{
    this->sections = sections;
}
vector<Section *> &Year::getSections()
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
        os << section->getObjectID()<<std::endl;
    }
    return os;
}
std::istream &operator>>(std::istream &is, Year &year)
{
    long ObjectID;
    is >> ObjectID;
    year.setObject(ObjectID);
    int yearNumber;
    is >> yearNumber;
    year.setYearNumber(yearNumber);
    long sectionID;
    while (is >> sectionID)
    {
        year.sections.push_back(getObject<Section>(sectionID));
    }
    return is;
}