/*
 * Group.h
 *
 *  Created on: Jun 13, 2024
 *      Author: kali9
 */

#ifndef GROUP_H_
#define GROUP_H_

#include <iostream>
#include <vector>

class Group {
    long ObjectID;
    int groupNumber;
    long section;
    long timetable;
    std::vector<long > students;
public:
    long getObjectID() const { return ObjectID; }
    void setObject(long);
    Group(int gnum=0, long sec=-1, long tt=-1);
    void addStudent(long student);
    void setSection(long  Sec=-1);
    long getSection() const;
   long getTimeTable() const;
    void setTimetable(long tt=-1);
    int getGroupNumber() const;
    void setGroupNumber(int gnum);
    friend std::ostream &operator<<(std::ostream &os, const Group &Group);
    friend std::istream &operator>>(std::istream &is, Group &Group);
};



#endif /* GROUP_H_ */
