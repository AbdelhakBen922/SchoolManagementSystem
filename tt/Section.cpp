/*
 * Section.cpp
 *
 *  Created on: Jun 13, 2024
 *      Author: kali9
 */

#include "Section.h"
#include <iostream>
#include <vector>
using std::ostream;
using std::istream;

Section::Section(long y, int sn) : year(y), sectionNumber(sn) {
	ObjectID=GetNewID("Section");
}

void Section::setGroups(vector<long> gs)
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
    out << section.year << "\n";
    for (auto &group : section.groups)
    {
        out << group<< "\n";
    }
    return out;
}
istream &operator>>(istream &in, Section &section)
{
	std::string ignore;
	std::getline(in,ignore);
    in >> section.ObjectID;
    in >> section.sectionNumber;
    in >> section.year;
    long id;
 	 while (in >> id)
    {
        section.groups.push_back(id);
    }
    return in;
}

void Section::setObject(long ObjectID)
   {
       if (ObjectNew(ObjectID,"Section"))
       {
           this->ObjectID = ObjectID;
       }
       else
           ObjectID = 0;
   };
   long Section::getYear()const{
       return year;
   }
