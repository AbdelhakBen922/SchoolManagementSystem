#include "Group.h"
#include "Section.h"
#include "Student.h"


Group::Group(int gnum, Section *sec, Schedule *tt) {
    ObjectID = GetNewID("Group");
    setGroupNumber(gnum);
    setSection(sec);
    setTimetable(tt);


}

void Group::addStudent(Student *student)
{
    students.push_back(student);
}

void Group::setSection(Section *Sec)
{
    section = Sec;
}
Section *Group::getSection() const
{
    return section;
}
Schedule *Group::getTimeTable() const
{
    return timetable;
}

void Group::setTimetable(Schedule *tt)
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
    os << group.groupNumber << std::endl;
    os << group.section->getObjectID() << std::endl;
   
    os << group.timetable->getObjectID() << std::endl;
     for (auto student : group.students)
    {
        os << student->getObjectID() << std::endl;
    }
    return os;
}

std::istream &operator>>(std::istream &is, Group &group)
{
    is >> group.groupNumber ;
    long sectionID, timetableID,tempStudent;
    vector<long> studentIDs;
    is >> sectionID >> timetableID;
    while(is>>tempStudent)
    {
        studentIDs.push_back(tempStudent);
    }
    group.setTimetable(getObject<Schedule>(timetableID));
    group.setSection(getObject<Section>(sectionID));
    for (auto studentID : studentIDs)
    {
        group.addStudent(getObject<Student>(studentID));
    }
    return is;
}