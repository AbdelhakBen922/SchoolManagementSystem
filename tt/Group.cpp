/*
 * Group.cpp
 *
 *  Created on: Jun 13, 2024
 *      Author: kali9
 */

#include "Group.h"
#include "funcs.h"


Group::Group(int gnum, long sec, long tt) {
    ObjectID = GetNewID("Group");
    setGroupNumber(gnum);
    setSection(sec);
    setTimetable(tt);


}

void Group::addStudent(long student)
{
    students.push_back(student);
}

void Group::setSection(long Sec)
{
    section = Sec;
}
long Group::getSection() const
{
    return section;
}
long Group::getTimeTable() const
{
    return timetable;
}

void Group::setTimetable(long tt)
{
    timetable = tt;
}


int Group::getGroupNumber() const
{
    return groupNumber;
}

void Group::setGroupNumber(int gnum)
{
    groupNumber = gnum;
}
std::ostream &operator<<(std::ostream &os, const Group &group)
{
    os << group.ObjectID<<std::endl;
    os << group.groupNumber << std::endl;
    os << group.section<< std::endl;

    os << group.timetable << std::endl;
     for (auto student : group.students)
    {
        os << student << std::endl;
    }
    return os;
}

std::istream &operator>>(std::istream &is, Group &group)
{
	std::string ignore;
	std::getline(is,ignore);
    is >>group.ObjectID;
    is >> group.groupNumber ;
    long sectionID, timetableID,tempStudent;
    std::vector<long> studentIDs;
    is >> sectionID >> timetableID;
    while(is>>tempStudent)
    {
        studentIDs.push_back(tempStudent);
    }
    group.setTimetable(timetableID);
    group.setSection(sectionID);
    for (auto studentID : studentIDs)
    {
        group.addStudent(studentID);
    }
    return is;
}
void Group::setObject(long ObjectID)
{
    if (ObjectNew(ObjectID,"Place"))
    {
        this->ObjectID = ObjectID;
    }
    else
        ObjectID = 0;
}
