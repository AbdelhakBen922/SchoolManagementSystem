#pragma once
#include <iostream>
#include <vector>
#include "Group.h"
#include "SchoolManagementSystem.h"

#include "Year.h"
class Year;
class Group;
using std::vector;
using std::string;
class Section {

    long ObjectID;

public:
    long getObjectID() const { return ObjectID; }
    void setObject(long)
    {
        if (ObjectNew(ObjectID,"Section"))
        {
            this->ObjectID = ObjectID;
        }
        else
            ObjectID = 0;
    };

private:
    int sectionNumber;
    Year *year;
    std::vector<Group *> groups;

public:
    Section(Year *y=nullptr, int sn=0);
    void setGroups(vector<Group *>);
    int getSectionNumber() const;
    void setSectionNumber(int sn);
    friend std::ostream &operator<<(std::ostream &os, const Section &Section);
    friend std::istream &operator>>(std::istream &is, Section &Section);
};

