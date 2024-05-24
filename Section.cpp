#include "Section.h"
#include <iostream>
#include <vector>
using std::ostream;
using std::istream;

Section::Section(Year *y, int sn) : year(y), sectionNumber(sn) {}

void Section::setGroups(vector<Group *> gs)
{
    groups = gs;
}

int Section::getSectionNumber() const
{
    return sectionNumber;
}

void Section::setSectionNumber(int sn)
{
    sectionNumber = sn;
}
ostream &operator<<(ostream &out, const Section &section)
{
    out << section.ObjectID << "\n";
    out << section.sectionNumber << "\n";
    out << section.year->getObjectID() << "\n";
    for (auto &group : section.groups)
    {
        out << group->getObjectID()<< "\n";
    }
    return out;
}
istream &operator>>(istream &in, Section &section)
{
    in >> section.ObjectID;
    in >> section.sectionNumber;
    long id;
    in >> id;
    section.year = getObject<Year>(id);
    while (in >> id)
    {
        section.groups.push_back(getObject<Group>(id));
    }
    return in;
}